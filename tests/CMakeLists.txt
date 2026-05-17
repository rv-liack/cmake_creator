add_executable(sample_test
    sample_test.cpp
)

target_include_directories(sample_test
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

add_test(NAME sample_test COMMAND sample_test)
