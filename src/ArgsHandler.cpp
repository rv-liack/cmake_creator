#include "../include/ArgsHandler.hpp"
#include <string_view>
#include <iostream>
#include <stdio.h>


namespace cmake_creator {

bool isAction(const char* str) {
    for (auto& action : definedActions) {
        if (action == std::string_view(str)) {
            return true;
        }
    }

    return false;
}


bool promptProjectData(ProjectData& data) {
    printf("Project name: ");
    if (!std::getline(std::cin, data.name)) return false;
    printf("Project version: ");
    if (!std::getline(std::cin, data.version)) return false;
    printf("Output path: ");
    if (!std::getline(std::cin, data.outputPath)) return false;
    printf("Cmake version: ");
    if (!std::getline(std::cin, data.cmakeVersion)) return false;
    return true;
}

} // namespace cmake_creator
