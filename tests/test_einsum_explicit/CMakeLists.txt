cmake_minimum_required(VERSION 3.21)
project(test_einsum)

set(CMAKE_CXX_STANDARD 17)


# explicit einsum
# single expressions
add_executable(test_einsum_explicit_1 test_einsum_explicit_1.cpp)
add_test(test_einsum_explicit_1 test_einsum_explicit_1)
set_property(TARGET test_einsum_explicit_1 PROPERTY CXX_STANDARD 17)

if(MSVC)
    target_compile_options(test_einsum_explicit_1 PRIVATE "/W2" "$<$<CONFIG:RELEASE>:/O2>")
else()
    target_compile_options(test_einsum_explicit_1 PRIVATE "$<$<CONFIG:RELEASE>:-O3>" "$<$<CONFIG:RELEASE>:-march=native>")
endif()

target_include_directories(test_einsum_explicit_1 PRIVATE ${FASTOR_INCLUDE_DIR})
target_include_directories(test_einsum_explicit_1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../)


# by pair
add_executable(test_einsum_explicit_2 test_einsum_explicit_2.cpp)
add_test(test_einsum_explicit_2 test_einsum_explicit_2)
set_property(TARGET test_einsum_explicit_2 PROPERTY CXX_STANDARD 17)

if(MSVC)
    target_compile_options(test_einsum_explicit_2 PRIVATE "/W2" "$<$<CONFIG:RELEASE>:/O2>")
else()
    target_compile_options(test_einsum_explicit_2 PRIVATE "$<$<CONFIG:RELEASE>:-O3>" "$<$<CONFIG:RELEASE>:-march=native>")
endif()

target_include_directories(test_einsum_explicit_2 PRIVATE ${FASTOR_INCLUDE_DIR})
target_include_directories(test_einsum_explicit_2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../)


# 3 tesnor network and beyond
add_executable(test_einsum_explicit_3 test_einsum_explicit_3.cpp)
add_test(test_einsum_explicit_3 test_einsum_explicit_3)
set_property(TARGET test_einsum_explicit_3 PROPERTY CXX_STANDARD 17)

if(MSVC)
    target_compile_options(test_einsum_explicit_3 PRIVATE "/W2" "$<$<CONFIG:RELEASE>:/O2>")
else()
    target_compile_options(test_einsum_explicit_3 PRIVATE "$<$<CONFIG:RELEASE>:-O3>" "$<$<CONFIG:RELEASE>:-march=native>")
endif()

target_include_directories(test_einsum_explicit_3 PRIVATE ${FASTOR_INCLUDE_DIR})
target_include_directories(test_einsum_explicit_3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../)
