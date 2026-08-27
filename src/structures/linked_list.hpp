/***********************************************************************************************
    Project: Algorithm Library
    File: linked_list.hpp
    Date created: 26. 8. 2026
    Last changed: 26. 8. 2026
    Author: Stepan Horenek
    
    Description: Impelementation of linked list using templates
***********************************************************************************************/
/**
 *  @file linked_list.hpp
 *  @brief Implementation of linked list via templates
 *
 *  Implementation of linked list via templates
 *
 *  @author Stepan Horenek
 *  @date 26. 8. 2026
*/

#include <vector>
#include <stdexcept>

/** 
 *  @brief Implementation of Linked List data structure
 *  @tparam T Template for data type of values contained in nodes of the list
*/
template<typename T>
class LinkedList{
public:
    /**
     *  @brief Initializes LinkedList class
    */
    LinkedList(){
        first = nullptr;
        active = nullptr;
    }
    /**
     *  @brief Checks if linked list is currently active
     *  @return true if active, false otherwise
    */
    bool IsActive(){
        return active != nullptr;
    }
    /**
     *  @brief Inserts node with data at the start of the linked list
     *  @param data data to be inserted into list
    */
    void InsertFirst(T data){
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = first;
        first = new_node;
    }
    /**
     *  @brief Returns value saved in first node of the linked list
     *  @return value saved in first node, error if list empty
    */
    T GetFirst(){
        if (first == nullptr){
            throw std::underflow_error("Can't get value of first in empty list");
        }
        return first->data;
    }
    /**
     *  @brief Returns value saved in active node
     *  @return value saved in active node, error if list inactive
    */
    T GetValue(){
        if (IsActive()){
            return active->data;
        }
        throw std::underflow_error("Can't get value of active in inactive list");
    }
    /**
     *  @brief Deletes first node of linked list
    */
    void DeleteFirst(){
        if (first != nullptr){
            if (first == active){
                active = nullptr;
            }
            Node* tmp = first;
            first = first->next;
            delete tmp;
        }
    }
    /**
     *  @brief Sets first node as active node
    */
    void First(){
        active = first;
    }
    /**
     *  @brief Moves active node pointer to node behind active node
    */
    void Next(){
        if (IsActive()){
            active = active->next;
        }
    }
    /**
     *  @brief Sets value inside active node
     *  @param data value to be saved inside active node
    */
    void SetValue(T data){
        if (IsActive()){
            active->data = data;
        }
    }
    /**
     *  @brief Inserts node after active node
     *  @param data value saved in new node
    */
    void InsertAfter(T data){
        if (IsActive()){
            Node* new_node = new Node;
            new_node->data = data;
            new_node->next = active->next;
            active->next = new_node;
        }
    }
    /**
     *  @brief Deletes node after active node
    */
    void DeleteAfter(){
        if (IsActive()){
            if (active->next != nullptr){
                Node* tmp = active->next;
                active->next = active->next->next;
                delete tmp;
            }
        }
    }
    /**
     *  @brief Returns length of linked list
     *  @return number of nodes in linked list
    */
    int Length(){
        int length = 0;
        First();
        while(IsActive()){
            length++;
            Next();
        }
        return length;
    }
    /**
     *  @brief Reverses linked list
    */
    void Reverse(){
        if (IsActive()){
            First();
            Next();
            Node* tmp = first;
            while(IsActive()){
                tmp->next = active->next;
                active->next = tmp;
                first = active;
                active = tmp->next;
            }
        }
    }
    /**
     *  @brief Destructor of linked list, deletes all nodes in linked list
    */
    ~LinkedList(){
        while(first != nullptr){
            DeleteFirst();
        }
        active = nullptr;
    }
private:
    struct Node{ // structure for items of list
        T data; // value saved in node
        Node* next; // pointer to next node
    };
    Node* first; // pointer to first node
    Node* active; // pointer to active node
}