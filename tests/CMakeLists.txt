add_executable(sample_test
    sample_test.cpp
    ${PROJECT_SOURCE_DIR}/src/ProjectManager.cpp
)

target_include_directories(sample_test
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

# Enable C++20 for tests as well
target_compile_features(sample_test PRIVATE cxx_std_20)

add_test(NAME sample_test COMMAND sample_test)
