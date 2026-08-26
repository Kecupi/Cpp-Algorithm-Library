/***********************************************************************************************
    Project: Algorithm Library
    File: structures.hpp
    Date created: 26. 8. 2026
    Last changed: 26. 8. 2026
    Author: Stepan Horenek
    
    Description: Library puts together all header files with structure implementations
***********************************************************************************************/
/**
 *  @file structures.hpp
 *  @brief library containing common data structures
 *
 *  Library puts together all header files with structure implementations
 *
 *  @author Stepan Horenek
 *  @date 26. 8. 2026
*/
#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <vector>

namespace Struct{

    template<typename T>
    class Stack{
        public:
            Stack(std::vector<T>& init_data) : data(std::move(init_data)){
            }

            void Push(T value){
                data.push_back(std::move(value));
            }

            T Pop(){
                if (Empty()){
                    throw std::out_of_range("Error: Can't pop from empty Stack!");
                }
                T tmp = std::move(data.back());
                data.pop_back();
                return tmp;
            }

            const T& Top() const{
                if (Empty()){
                    throw std::out_of_range("Error: Can't get item from empty Stack!");
                }
                return data.back();
            }

            size_t Size const(){
                return data.size();
            }

            bool const Empty(){
                return (Size() == 0);
            }
        private:
            std::vector<T> data;
    };


}

#endif