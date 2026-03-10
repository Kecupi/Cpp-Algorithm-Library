#ifndef SORTING_HPP
#define SORTING_HPP

#include vector
#include functional
#include utility

namespace Sorting{

    template<typename T>
    void MemberSwap(T& a, T& b){
        T tmp = std::move(a);
        a = std::move(b);
        b = std::move(tmp);
    }

    template <typename T, typename Compare = std::less<T>>
    void BubbleSort(std::vector<T>& array, Compare comp = Compare()){
        int arr_size = array.size();
        for (int iter = 0; iter < arr_size - 1; iter++){
            for (int idx = 0; idx < arr_size - 1; idx++){
                if (comp(array[idx], array[idx + 1])){
                    MemberSwap(array[idx], array[idx + 1]);
                }
            }
        }
    }

}

#endif