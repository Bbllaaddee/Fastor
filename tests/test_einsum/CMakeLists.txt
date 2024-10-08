cmake_minimum_required(VERSION 3.21)
project(test_einsum)

set(CMAKE_CXX_STANDARD 14)

# single einsum
# MSVC gives superfluous errors
if(NOT MSVC)
add_executable(test_einsum_single test_einsum_single.cpp)
add_test(test_einsum_single test_einsum_single)

if(MSVC)
    set_property(TARGET test_einsum_single PROPERTY CXX_STANDARD 17)
    target_compile_options(test_einsum_single PRIVATE "/W2" "$<$<CONFIG:RELEASE>:/O2>")
else()
    target_compile_options(test_einsum_single PRIVATE "$<$<CONFIG:RELEASE>:-O3>" "$<$<CONFIG:RELEASE>:-march=native>")
endif()

target_include_directories(test_einsum_single PRIVATE ${FASTOR_INCLUDE_DIR})
target_include_directories(test_einsum_single PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../)
endif()

# tensor contraction
# default
add_executable(test_contraction_0 test_contraction.cpp)
add_test(test_contraction_0 test_contraction_0)

if(MSVC)
    set_property(TARGET test_contraction_0 PROPERTY CXX_STANDARD 17)
    target_compile_options(test_contraction_0 PRIVATE "/W2" "$<$<CONFIG:RELEASE>:/O2>")
else()
    target_compile_options(test_contraction_0 PRIVATE "$<$<CONFIG:RELEASE>:-O3>" "$<$<CONFIG:RELEASE>:-march=native>")
endif()

target_include_directories(test_contraction_0 PRIVATE ${FASTOR_INCLUDE_DIR})
target_include_directories(test_contraction_0 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../)


# -DCONTRACT_OPT=1
add_executable(test_contraction_1 test_contraction.cpp)
add_test(test_contraction_1 test_contraction_1)

if(MSVC)
    set_property(TARGET test_contraction_1 PROPERTY CXX_STANDARD 17)
    target_compile_options(test_contraction_1 PRIVATE "/W2" "$<$<CONFIG:RELEASE>:/O2>")
else()
    target_compile_options(test_contraction_1 PRIVATE "$<$<CONFIG:RELEASE>:-O3>" "$<$<CONFIG:RELEASE>:-march=native>")
endif()

target_compile_definitions(test_contraction_1 PRIVATE CONTRACT_OPT=1)
target_include_directories(test_contraction_1 PRIVATE ${FASTOR_INCLUDE_DIR})
target_include_directories(test_contraction_1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../)


# -DCONTRACT_OPT=-1
add_executable(test_contraction_2 test_contraction.cpp)
add_test(test_contraction_2 test_contraction_2)

if(MSVC)
    set_property(TARGET test_contraction_2 PROPERTY CXX_STANDARD 17)
    target_compile_options(test_contraction_2 PRIVATE "/W2" "$<$<CONFIG:RELEASE>:/O2>")
else()
    target_compile_options(test_contraction_2 PRIVATE "$<$<CONFIG:RELEASE>:-O3>" "$<$<CONFIG:RELEASE>:-march=native>")
endif()

target_compile_definitions(test_contraction_2 PRIVATE CONTRACT_OPT=-1)
target_include_directories(test_contraction_2 PRIVATE ${FASTOR_INCLUDE_DIR})
target_include_directories(test_contraction_2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../)


# tensor einsum
# default
add_executable(test_einsum_0 test_einsum.cpp)
add_test(test_einsum_0 test_einsum_0)

if(MSVC)
    set_property(TARGET test_einsum_0 PROPERTY CXX_STANDARD 17)
    target_compile_options(test_einsum_0 PRIVATE "/W2" "$<$<CONFIG:RELEASE>:/O2>")
else()
    target_compile_options(test_einsum_0 PRIVATE "$<$<CONFIG:RELEASE>:-O3>" "$<$<CONFIG:RELEASE>:-march=native>")
endif()

target_include_directories(test_einsum_0 PRIVATE ${FASTOR_INCLUDE_DIR})
target_include_directories(test_einsum_0 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../)


# -DCONTRACT_OPT=1
add_executable(test_einsum_1 test_einsum.cpp)
add_test(test_einsum_1 test_einsum_1)

if(MSVC)
    set_property(TARGET test_einsum_1 PROPERTY CXX_STANDARD 17)
    target_compile_options(test_einsum_1 PRIVATE "/W2" "$<$<CONFIG:RELEASE>:/O2>")
else()
    target_compile_options(test_einsum_1 PRIVATE "$<$<CONFIG:RELEASE>:-O3>" "$<$<CONFIG:RELEASE>:-march=native>")
endif()

target_compile_definitions(test_einsum_1 PRIVATE CONTRACT_OPT=1)
target_include_directories(test_einsum_1 PRIVATE ${FASTOR_INCLUDE_DIR})
target_include_directories(test_einsum_1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../)


# -DCONTRACT_OPT=-1
add_executable(test_einsum_2 test_einsum.cpp)
add_test(test_einsum_2 test_einsum_2)

if(MSVC)
    set_property(TARGET test_einsum_2 PROPERTY CXX_STANDARD 17)
    target_compile_options(test_einsum_2 PRIVATE "/W2" "$<$<CONFIG:RELEASE>:/O2>")
else()
    target_compile_options(test_einsum_2 PRIVATE "$<$<CONFIG:RELEASE>:-O3>" "$<$<CONFIG:RELEASE>:-march=native>")
endif()

target_compile_definitions(test_einsum_2 PRIVATE CONTRACT_OPT=-1)
target_include_directories(test_einsum_2 PRIVATE ${FASTOR_INCLUDE_DIR})
target_include_directories(test_einsum_2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../)
