cmake_minimum_required(VERSION 3.14)
project(AlgorithmLibrary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY  https://github.com/google/googletest.git
    GIT_TAG         main
    GIT_SUBMODULES_RECURSE on
)
FetchContent_MakeAvailable(googletest)
set(ALGORITM_LIBRARIES "sorting" "structures")
foreach(ALGO ${ALGORITM_LIBRARIES})
    file(GLOB ALGO_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/${ALGO}/*.cpp")
    add_library(${ALGO} ${ALGO_SRC} "${CMAKE_CURRENT_SOURCE_DIR}/src/${ALGO}/${ALGO}.hpp")
    target_include_directories(${ALGO} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/${ALGO}")

    set(TEST "test_${ALGO}")
    add_executable(${TEST} ${CMAKE_CURRENT_SOURCE_DIR}/tests/${TEST}.cpp)
    target_link_libraries(${TEST} PRIVATE ${ALGO} GTest::gtest_main)

    gtest_discover_tests(${TEST})
endforeach()