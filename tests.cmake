add_executable(unit_tests tests/unit_tests.cpp)
target_link_libraries(unit_tests PRIVATE jlizard::logger)
target_include_directories(unit_tests PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/tests")

add_test(NAME "Unit Tests" COMMAND unit_tests)