cmake_minimum_required(VERSION 3.14)
project(AlgorithmLibrary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY  https://github.com/google/googletest.git
    GIT_TAG         main
    GIT_SUBMODULES_RECURSE on
)

FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)

set(ALGORITM_LIBRARIES "sorting")
foreach(ALGO ${ALGORITM_LIBRARIES})
    add_library(${ALGO} INTERFACE)
    target_include_directories(${ALGO} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src/${ALGO}")

    set(TEST "test_${ALGO}")
    add_executable(${TEST} ${CMAKE_CURRENT_SOURCE_DIR}/tests/${TEST}.cpp)
    target_link_libraries(${TEST} PRIVATE ${ALGO} GTest::gtest_main)

    gtest_discover_tests(${TEST})
endforeach()