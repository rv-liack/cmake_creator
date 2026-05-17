#include <iostream>
#include <cassert>
#include <string>
#include "../include/ProjectManager.hpp"
#include "../include/ArgsHandler.hpp"

using namespace cmake_creator;

void test_cmake_content_generation() {
    ProjectData data;
    data.name = "TestProject";
    data.version = "2.1.0";
    data.cmakeVersion = "3.22";

    std::string content = getCMakeFileContent(data);
    
    assert(content.find("project(TestProject VERSION 2.1.0)") != std::string::npos);
    assert(content.find("cmake_minimum_required(VERSION 3.22)") != std::string::npos);
    assert(content.find("add_executable(TestProject") != std::string::npos);
    
    std::cout << "[PASS] test_cmake_content_generation\n";
}

void test_main_content_generation() {
    ProjectData data;
    data.name = "HelloWorld";

    std::string content = getMainFileContent(data);
    
    assert(content.find("printf(\"Hola mundo desde HelloWorld\");") != std::string::npos);
    
    std::cout << "[PASS] test_main_content_generation\n";
}

int main() {
    try {
        test_cmake_content_generation();
        test_main_content_generation();
        std::cout << "\nAll tests passed successfully!\n";
    } catch (const std::exception& e) {
        std::cerr << "\nTest failed with exception: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
