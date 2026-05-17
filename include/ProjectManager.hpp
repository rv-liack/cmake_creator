#pragma once

#include <string>
#include <filesystem>

namespace cmake_creator {

namespace fs = std::filesystem;

/**
 * @struct File
 * @brief Represents a file to be created within the project structure.
 */
struct File {
    std::string name;    ///< File name (e.g., "main.cpp").
    std::string content; ///< Full text content of the file.

    File(const std::string& fileName);
};

struct ProjectData;

/**
 * @brief Orchestrates the creation of the entire project folder and files.
 * @param data Configuration of the project to be created.
 * @return true on success, false if any step (dir creation, file writing) fails.
 */
bool createProject(const ProjectData& data);

/**
 * @brief Helper to write a File object to a specific disk path.
 * @param path The directory where the file should be saved.
 * @param file The File object containing name and content.
 * @return true if file was written successfully.
 */
bool writeFile(const fs::path& path, File& file);

/**
 * @brief Generates the default content for the main.cpp file.
 */
std::string getMainFileContent(const ProjectData& data);

/**
 * @brief Generates the content for the CMakeLists.txt file.
 */
std::string getCMakeFileContent(const ProjectData& data);

/**
 * @brief Safely creates a directory if it doesn't already exist.
 * @param fullPath Complete path to create.
 * @return true if directory exists or was created successfully.
 */
bool createDir(const fs::path& fullPath);

/**
 * @brief Normalizes a path string into a filesystem path object.
 */
fs::path formatPath(const fs::path& pathStr);

} // namespace cmake_creator
