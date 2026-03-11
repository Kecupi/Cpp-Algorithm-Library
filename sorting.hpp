#ifndef SORTING_HPP
#define SORTING_HPP

#include <vector>
#include <functional>
#include <utility>

namespace Sorting{

    template<typename T>
    void MemberSwap(T& a, T& b){
        T tmp = std::move(a);
        a = std::move(b);
        b = std::move(tmp);
    }

    template <typename T, typename Compare = std::less<T>>
    void BubbleSort(std::vector<T>& array, Compare comp = Compare()){
        size_t arr_size = array.size();
        for (size_t iter = 0; iter < arr_size - 1; iter++){
            for (size_t idx = 0; idx < arr_size - 1; idx++){
                if (comp(array[idx + 1], array[idx])){
                    MemberSwap(array[idx], array[idx + 1]);
                }
            }
        }
    }

    template <typename T, typename Compare = std::less<T>>
    void SelectionSort(std::vector<T>& array, Compare comp = Compare()){
        size_t arr_size = array.size();
        size_t swappable_idx;
        for (size_t idx_out = 0; idx_out < arr_size; idx_out++){
            swappable_idx = idx_out;
            for (size_t idx_in = idx_out + 1; idx_in < arr_size; idx_in++){
                if (comp(array[idx_in], array[swappable_idx])){
                    swappable_idx = idx_in;
                }
            }
            MemberSwap(array[idx_out], array[swappable_idx]);
        }
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

    template<typename T, typename Compare = std::less<T>>
    void QuickSortManual(std::vector<T>& array, int low, int high, Compare comp = Compare()){
        if (low < high){
            int part_idx = Partition(array, low, high, comp);
            QuickSortManual(array, low, part_idx - 1, comp);
            QuickSortManual(array, part_idx + 1, high, comp);
        }
    }

    template <typename T, typename Compare = std::less<T>>
    void QuickSortAuto(std::vector<T>& array, Compare comp = Compare()){
        QuickSortManual(array, 0, array.size() - 1, comp);
    }

}

#endif