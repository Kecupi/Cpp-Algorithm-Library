/***********************************************************************************************
    Project: Algorithm Library
    File: test_sorting.cpp
    Date created: 24. 8. 2026
    Last changed: 24. 8. 2026
    Author: Stepan Horenek
    
    Description: Tests for library of sorting algorithms
***********************************************************************************************/
/**
 *  @file test_sorting.cpp
 *  @brief Tests for library of sorting algorithms
 *
 *  File for testing all of the sorting algorithms in sorting.hpp in src/ of this project
 *
 *  @author Stepan Horenek
 *  @date 24. 8. 2026
*/

#include <gtest/gtest.h>
#include "sorting.hpp"

template<typename T>
class SortingSuite : public ::testing:: Test{
    public:
        template<typename func>
        void RunTest(func sort_func){
            std::vector<T> empty;
            EXPECT_NO_THROW(sort_func(empty));
            EXPECT_TRUE(empty.empty());
        }
};
using DataTypes = ::testing::Types<int, char, float>;
TYPED_TEST_SUITE(SortingSuite, DataTypes);

TYPED_TEST(SortingSuite, BubbleSort){
    this->RunTest([](std::vector<TypeParam>& array){Sort::BubbleSort(array);});
}
TYPED_TEST(SortingSuite, SelectionSort){
    this->RunTest([](std::vector<TypeParam>& array){Sort::SelectionSort(array);});
}
TYPED_TEST(SortingSuite, QuickSort){
    this->RunTest([](std::vector<TypeParam>& array){Sort::QuickSort(array);});
}