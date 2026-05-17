#include <cstdio>
#include <filesystem>
#include <fstream>
#include <string>
#include <format>

#include "../include/ProjectManager.hpp"
#include "../include/ArgsHandler.hpp"

namespace cmake_creator {

File::File(const std::string& fileName) : name(fileName) {}

bool writeFile(const fs::path& path, File& file) {
    fs::path fullPath = path / file.name;
    std::ofstream f(fullPath);

    if (f.is_open()) {
        f << file.content;
        return true;
    }

    return false;
}

std::string getMainFileContent(const ProjectData& data) {
    return std::format(
R"(#include <stdio.h>

int main(){{
    printf("Hola mundo desde {}");
    return 0;
}}
)", data.name);
}

std::string getCMakeFileContent(const ProjectData& data) {
    return std::format(
        "cmake_minimum_required(VERSION {})\n"
        "project({} VERSION {})\n\n"
        "add_executable({}\n"
        "    src/main.cpp\n"
        ")\n",
        data.cmakeVersion,
        data.name,
        data.version,
        data.name
    );
}

bool createDir(const fs::path& fullPath) {
    if (fs::exists(fullPath)) return true;
    
    std::error_code ec;
    if (!fs::create_directories(fullPath, ec)) {
         return false;
    }

    return true;
}

bool createProject(const ProjectData& data) {
    fs::path projectPath = fs::path(data.outputPath) / data.name;

    if (!createDir(projectPath)) return false;
    if (!createDir(projectPath / "include")) return false;
    if (!createDir(projectPath / "src")) return false;

    File cmakeFile{"CMakeLists.txt"};
    cmakeFile.content = getCMakeFileContent(data);
    if (!writeFile(projectPath, cmakeFile)) return false;

    File mainFile{"main.cpp"};
    mainFile.content = getMainFileContent(data);
    if (!writeFile(projectPath / "src", mainFile)) return false;

    return true;
}

fs::path formatPath(const fs::path& pathStr) {
    fs::path p(pathStr);
    if (!p.empty() && p.has_filename()) {
        p /= "";
    }
    return p;
}

} // namespace cmake_creator
