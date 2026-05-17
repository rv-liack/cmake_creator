#include <cstdio>
#include <string>

#include "../include/ArgsHandler.hpp"
#include "../include/ProjectManager.hpp"

using namespace cmake_creator;

int main(int argc, const char** args) {
    if (argc <= 1) {
        printf("Usage: cmake_creator <action> [args]\n");
	printf("Actions: new\n");
	printf("Actions: new <project_name> <creation_path (current directory by defautl)>\n");
        return -1;
    }

    auto action = args[1];

    if (!isAction(action)) {
        printf("Error: Invalid action '%s'\n", action);
        return -1;
    }

    if (std::string(action) == "new") {
        ProjectData p;
        bool interactive = (argc == 2);

        if (interactive) {
            printf("--- New Project (Interactive Mode) ---\n");
            if (!promptProjectData(p)) {
                printf("Error: Failed to read input.\n");
                return -1;
            }
        } else {
            p.name = args[2];
            if (argc >= 4) {
                p.outputPath = args[3];
            }
            printf("--- New Project (Static Mode: %s) ---\n", p.name.c_str());
        }

        if (createProject(p)) {
            printf("Success: Project '%s' created at '%s'\n", p.name.c_str(), p.outputPath.c_str());
            return 0;
        } else {
            printf("Error: Could not create project. Check permissions or path validity.\n");
            return -1;
        }
    }

    return 0;
}
