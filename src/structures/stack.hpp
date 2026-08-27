/***********************************************************************************************
    Project: Algorithm Library
    File: stack.hpp
    Date created: 27. 8. 2026
    Last changed: 27. 8. 2026
    Author: Stepan Horenek
    
    Description: Impelementation of stack using templates
***********************************************************************************************/
/**
 *  @file stack.hpp
 *  @brief Implementation of stack via templates
 *
 *  Implementation of stack via templates
 *
 *  @author Stepan Horenek
 *  @date 27. 8. 2026
*/

#include <vector>
#include <stdexcept>

/** 
 *  @brief Implementation of Stack data structure
 *  @tparam T Template for data type of values contained in nodes of stack
*/
template <typename T>
class Stack{
public:
    /**
     *  @brief Initializes Stack class
    */
    Stack(){
        top = nullptr;
    }
    /**
     *  @brief Checks if stack is currently empty
     *  @return true if active, false otherwise
    */
    bool IsEmpty(){
        return top == nullptr;
    }
    /**
     *  @brief Pushes value at top of stack
     *  @param value value to be pushed at top of stack
    */
    void Push(T value){
        Node* new_node = new Node;
        new_node->data = value;
        new_node->prev = top;
        top = new_node;
    }
    /**
     *  @brief Returns stack size
     *  @return size of stack
    */
    int Size(){
        int size = 0;
        Node* tmp = top;
        while (tmp != nullptr){
            size++;
            tmp = tmp->prev;
        }
        return size;
    }
    /**
     *  @brief Removes node from top of stack
    */
    void Pop(){
        if (!IsEmpty()){
            if (Size() != 0){
                Node* tmp = top;
                top = tmp->prev;
                delete tmp;
            }
        }
    }
    /**
     *  @brief Returns value in node on top of the stack
     *  @return value from top of the stack
    */
    T Top(){
        if (IsEmpty()){
            throw std::out_of_range("Error: Can't get item from empty Stack!");
        }
        return top->data;
    }
    /**
     *  @brief Destructor of stack, deletes all nodes
    */
    ~Stack(){
        while(top != nullptr){
            Pop();
        }
        top = nullptr;
    }
private:
    struct Node{
        T data; // value saved in node
        Node* prev; // pointer to previous node
    };
    Node* top; // current top node of stack
};