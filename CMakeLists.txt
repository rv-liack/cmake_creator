cmake_minimum_required(VERSION 3.16)

project(cmake_creator VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/ProjectManager.cpp
    src/ArgsHandler.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

include(CTest)
if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
