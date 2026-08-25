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
#include <algorithm>
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

        /**
            @brief Patrition function (Lomuto) for quick sort
            @tparam T type of template objects to be swapped
            @tparam Compare type of comparator function used for sorting
            @param array vector of template object to be sorted
            @param low lowest index of vector to be sorted
            @param high highest index of vector to be sorted
            @param comp comparator to be used to sort array
        */
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
            @brief Sorts vector of template object using quick sort, can sort just part based on input
            @tparam T type of template objects to be swapped
            @tparam Compare type of comparator function used for sorting
            @param array vector of template object to be sorted
            @param low lowest index of vector to be sorted
            @param high highest index of vector to be sorted
            @param comp comparator to be used to sort array
        */
        template<typename T, typename Compare = std::less<T>>
        void QSortHelp(std::vector<T>& array, int low, int high, Compare comp = Compare()){
            if (array.size() == 0) return;
            if (low < high){
                int part_idx = Partition(array, low, high, comp);
                QSortHelp(array, low, part_idx - 1, comp);
                QSortHelp(array, part_idx + 1, high, comp);
            }
        }

        /**
        @brief Merge function for merge sort implementations
        @tparam T type of template objects to be swapped
        @tparam Compare type of comparator function used for sorting
        @param dest vector of template object to save saved halves into
        @param left lowest index of vector to be sorted
        @param right highest index of vector to be sorted
        @param comp comparator to be used to sort dest
        @param dest vector of template object containing halves to be merged
        */
        template <typename T, typename Comp = std::less<T>>
        void Merge(std::vector<T>& dest, int left, int mid, int right, Compare comp = compare(), std::vector<T>& dest){
            int left_idx = left;
            int mid_idx = mid;
            for (int idx = left; idx < right; idx++){
                if (left_idx < middle && (mid_idx >= right || comp(dest[left_idx], dest[mid_idx]))){
                    dest[idx] = dest[left_idx];
                    left_idx++;
                } else {
                    dest[idx] = dest[mid_idx];
                    mid_idx++;
                }
            }
        }

        /**
        @brief Sorts vector of template object using merge sort function
        @tparam T type of template objects to be swapped
        @tparam Compare type of comparator function used for sorting
        @param array vector of template object to be used for saving sorted halves in current step
        @param left lowest index of vector to be sorted
        @param right highest index of vector to be sorted
        @param comp comparator to be used to sort array
        @param copy vector of template object to be used for copying sorted halves in current step
        */
        template <typename T, typename Compare = std::less<T>>
        void MSortTopDown(std::vector<T>& array, int left, int right, Compare comp = Compare(), std::vector<T>& copy){
            if (left < right){
                int mid = (left + right) / 2;
                MSortTopDown(copy, left, mid, comp, array);
                MSortTopDown(copy, mid+1, right, comp, array);
                Merge(copy, left, mid, right, comp, array);
            }
        }
    }
    /**
        @brief Sorts vector of template object using bubble sort
        @tparam T type of template objects to be swapped
        @tparam Compare type of comparator function used for sorting
        @param array vector of template object  to be sorted
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
        @param array vector of template object to be sorted
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
        @brief Sorts vector of template object using general quicksort function
        @tparam T type of template objects to be swapped
        @tparam Compare type of comparator function used for sorting
        @param array vector of template object to be sorted
        @param comp comparator to be used to sort array
    */
    template <typename T, typename Compare = std::less<T>>
    void QuickSort(std::vector<T>& array, Compare comp = Compare()){
        if (array.size() == 0) return;
        detail::QSortHelp(array, 0, array.size() - 1, comp);
    }

    /**
        @brief Sorts vector of template object using insertion sort function
        @tparam T type of template objects to be swapped
        @tparam Compare type of comparator function used for sorting
        @param array vector of template object to be sorted
        @param comp comparator to be used to sort array
    */
    template <typename T, typename Compare = std::less<T>>
    void InsertionSort(std::vector<T>& array, Compare comp = Compare()){
        if (array.size() == 0) return;
        size_t arr_size = array.size();
        for (int idx = 1; idx < arr_size; idx++){
            T key = array[idx];
            int jdx = idx - 1;
            while ((jdx >= 0) && (comp(key, array[jdx]))){
                detail::MemberSwap(array[jdx + 1], array[jdx]);
                jdx--;
            }
            array[jdx+1] = key;
        }
    }

    /**
        @brief Sorts vector of template object using top down variant of merge sort
        @tparam T type of template objects to be swapped
        @tparam Compare type of comparator function used for sorting
        @param array vector of template object to be sorted
        @param comp comparator to be used to sort array
    */
    template <typename T, typename Compare = std::less<T>>
    void MergeSortTopDown(std::vector<T>& array, Compare comp = Compare()){
        if (array.size() == 0) return;
        std::vector<T> copy{array};
        detail::MSortTopDown(array, 0, array.size()-1, comp, copy);
    }

    /**
        @brief Sorts vector of template object using bottom up variant of merge sort
        @tparam T type of template objects to be swapped
        @tparam Compare type of comparator function used for sorting
        @param array vector of template object to be sorted
        @param comp comparator to be used to sort array
    */
    template <typename T, typename Compare = std::less<T>>
    void MergeSortBottomUp(std::vector<T>& array, Compare comp = Compare()){
        if (array.size() == 0) return;
        size_t arr_size = array.size();
        std::vector<T> copy{array};
        for (int size = 1; size < arr_size; size *= 2){
            for (int idx = 0; idx < arr_size; idx = idx + 2*size){
                detail::Merge(array, idx, std::min(idx + size, arr_size), std::min(idx + 2*size), comp, copy)
            }
            array = copy;
        }
    }
}

#endif