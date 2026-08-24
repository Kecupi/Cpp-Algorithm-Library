/***********************************************************************************************
    Project: Algorithm Library
    File: sorting.hpp
    Date created: 24. 8. 2026
    Last changed: 24. 8. 2026
    Author: Stepan Horenek
    
    Description: Library containts most common sorting algorithm implementation using templates
***********************************************************************************************/
/**
 *  @file sorting.hpp
 *  @brief library containing common algorithms
 *
 *  Library containing most common sorting algorithm implementation using templates
 *
 *  @author Stepan Horenek
 *  @date 24. 8. 2026
*/

#ifndef SORTING_HPP
#define SORTING_HPP

#include <vector>
#include <functional>
#include <utility>

namespace Sort{
    namespace detail{
        /**
            @brief Swaps two template objects
            @tparam T type of template objects to be swapped
            @param a reference to template object to be swapped
            @param b reference to template object to be swapped
        */
        template<typename T>
        void MemberSwap(T& a, T& b){
            T tmp = std::move(a);
            a = std::move(b);
            b = std::move(tmp);
        }

        template<typename T, typename Compare = std::less<T>>
        int Partition(std::vector<T>& array, int low, int high, Compare comp = Compare()){
            int pivot = array[high];
            int idx = low - 1;
            for (int jdx = low; jdx < high; jdx++){
                if (comp(array[jdx], pivot)){
                    idx++;
                    MemberSwap(array[idx], array[jdx]);
                }
            }
            MemberSwap(array[idx+1], array[high]);
            return idx+1;
        }

        /**
            @brief Sorts vector of template object using quick sort, can sort only part based on input
            @tparam T type of template objects to be swapped
            @tparam Compare type of comparator function used for sorting
            @param array vector of template object using bubble sort
            @param comp comparator to be used to sort array
        */
        template<typename T, typename Compare = std::less<T>>
        void QuickSortGeneral(std::vector<T>& array, int low, int high, Compare comp = Compare()){
            if (array.size() == 0) return;
            if (low < high){
                int part_idx = Partition(array, low, high, comp);
                QuickSortGeneral(array, low, part_idx - 1, comp);
                QuickSortGeneral(array, part_idx + 1, high, comp);
            }
        }
    }
    /**
        @brief Sorts vector of template object using bubble sort
        @tparam T type of template objects to be swapped
        @tparam Compare type of comparator function used for sorting
        @param array vector of template object using bubble sort
        @param comp comparator to be used to sort array
    */
    template <typename T, typename Compare = std::less<T>>
    void BubbleSort(std::vector<T>& array, Compare comp = Compare()){
        size_t arr_size = array.size();
        if (arr_size == 0) return;
        for (size_t iter = 0; iter < arr_size - 1; iter++){
            for (size_t idx = 0; idx < arr_size - 1; idx++){
                if (comp(array[idx + 1], array[idx])){
                    detail::MemberSwap(array[idx], array[idx + 1]);
                }
            }
        }
    }

    /**
        @brief Sorts vector of template object using selection sort
        @tparam T type of template objects to be swapped
        @tparam Compare type of comparator function used for sorting
        @param array vector of template object using bubble sort
        @param comp comparator to be used to sort array
    */
    template <typename T, typename Compare = std::less<T>>
    void SelectionSort(std::vector<T>& array, Compare comp = Compare()){
        size_t arr_size = array.size();
        if (arr_size == 0) return;
        size_t swappable_idx;
        for (size_t idx_out = 0; idx_out < arr_size; idx_out++){
            swappable_idx = idx_out;
            for (size_t idx_in = idx_out + 1; idx_in < arr_size; idx_in++){
                if (comp(array[idx_in], array[swappable_idx])){
                    swappable_idx = idx_in;
                }
            }
            detail::MemberSwap(array[idx_out], array[swappable_idx]);
        }
    }

    /**
        @brief Sorts vector of template object using general quicksort function, sorts whole array
        @tparam T type of template objects to be swapped
        @tparam Compare type of comparator function used for sorting
        @param array vector of template object using bubble sort
        @param comp comparator to be used to sort array
    */
    template <typename T, typename Compare = std::less<T>>
    void QuickSort(std::vector<T>& array, Compare comp = Compare()){
        if (array.size() == 0) return;
        detail::QuickSortGeneral(array, 0, array.size() - 1, comp);
    }
}

#endif