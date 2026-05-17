#pragma once

#include <string_view>
#include <string>

/**
 * @namespace cmake_creator
 * @brief Main namespace for the CMake Project Creator tool.
 */
namespace cmake_creator {

/**
 * @struct ProjectData
 * @brief Holds all the configuration needed to create a new C++ project.
 */
struct ProjectData {
    std::string name = "newProject";    ///< Name of the project and its main executable.
    std::string version = "1.0.0";      ///< Initial project version.
    std::string outputPath = ".";       ///< Directory where the project folder will be created.
    std::string cmakeVersion = "3.0";   ///< Minimum CMake version required in CMakeLists.txt.
};

/// List of supported CLI actions.
inline constexpr std::string_view definedActions[] = {"new"};

/**
 * @brief Checks if a given string matches any defined action.
 * @param actionName The string to check.
 * @return true if valid, false otherwise.
 */
bool isAction(const char* actionName);

/**
 * @brief Launches an interactive terminal prompt to fill ProjectData.
 * @param data Reference to the object that will store the user input.
 * @return true if all data was read successfully, false if input was interrupted.
 */
bool promptProjectData(ProjectData& data);

} // namespace cmake_creator
