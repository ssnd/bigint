add_executable(output_tests ${CMAKE_CURRENT_SOURCE_DIR}/output.cpp)
add_executable(init_tests ${CMAKE_CURRENT_SOURCE_DIR}/init.cpp)
add_executable(operator_tests ${CMAKE_CURRENT_SOURCE_DIR}/operators.cpp)
add_executable(arithmetic_tests ${CMAKE_CURRENT_SOURCE_DIR}/arithmetics.cpp)

target_link_libraries(output_tests bigint GTest::gtest_main)
target_link_libraries(operator_tests bigint GTest::gtest_main)
target_link_libraries(init_tests bigint GTest::gtest_main)
target_link_libraries(arithmetic_tests bigint GTest::gtest_main)

gtest_discover_tests(output_tests init_tests operator_tests arithmetic_tests)

add_executable(run_all ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        output.cpp
        init.cpp
        operators.cpp
        arithmetics.cpp
        )

target_link_libraries(run_all GTest::gtest_main bigint)

