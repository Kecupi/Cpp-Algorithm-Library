/***********************************************************************************************
    Project: Algorithm Library
    File: doubly_linked_list.hpp
    Date created: 26. 8. 2026
    Last changed: 27. 8. 2026
    Author: Stepan Horenek
    
    Description: Impelementation of doubly linked list using templates
***********************************************************************************************/
/**
 *  @file doubly_linked_list.hpp
 *  @brief Implementation of doubly linked list via templates
 *
 *  Implementation of doubly linked list via templates
 *
 *  @author Stepan Horenek
 *  @date 26. 8. 2026
*/

#include <vector>
#include <stdexcept>

/** 
 *  @brief Implementation of Doubly Linked List data structure
 *  @tparam T Template for data type of values contained in nodes of the list
*/
template <typename T>
Class DoublyLinkedList{
public:
    /**
     *  @brief Initializes DoublyLinkedList class
    */
    DoublyLinkedList(){
        first = nullptr;
        last = nullptr;
        active = nullptr;
    }
    /**
     *  @brief Checks if doubly linked list is currently active
     *  @return true if active, false otherwise
    */
    bool IsActive(){
        return active != nullptr;
    }
    /**
     *  @brief Inserts node with data at the start of the doubly linked list
     *  @param data data to be inserted into list
    */
    void InsertFirst(T data){
        Node* tmp = new Node;
        tmp->data = data;
        tmp->prev = nullptr;
        tmp->next = first;
        if (first != nullptr){
            first->prev = tmp;
        } else {
            last = tmp;
        }
        first = tmp;
    }
    /**
     *  @brief Inserts node with data at the end of the doubly linked list
     *  @param data data to be inserted into list
    */
    void InsertLast(T data){
        Node* tmp = new Node;
        tmp->data = data;
        tmp->prev = last;
        tmp->next = nullptr;
        if (first != nullptr){
            last->next = tmp;
        } else {
            first = tmp;
        }
        last = tmp;
    }
    /**
     *  @brief Returns value saved in first node of the doubly linked list
     *  @return value saved in first node, error if list empty
    */
    T GetFirst(){
        if (first == nullptr){
            throw std::underflow_error("Can't get value of first in empty list");
        }
        return first->data;
    }
    /**
     *  @brief Returns value saved in last node of the doubly linked list
     *  @return value saved in last node, error if list empty
    */
    T GetLast(){
        if (last == nullptr){
            throw std::underflow_error("Can't get value of last in empty list");
        }
        return last->data;
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
     *  @brief Deletes first node of doubly linked list
    */
    void DeleteFirst(){
        if (first != nullptr){
            if (first == active){
                active = nullptr;
            }
            Node* tmp = first;
            if (first != last){
                first = first->next;
                first->prev = nullptr;
            } else {
                first = nullptr;
                last = nullptr;
            }
            delete tmp;
        }
    }
    /**
     *  @brief Deletes last node of doubly linked list
    */
    void DeleteLast(){
        if (last != nullptr){
            if (last == active){
                active = nullptr;
            }
            Node* tmp = last;
            if (first != last){
                last = last->prev;
                last->next = nullptr;
            } else {
                first = nullptr;
                last = nullptr;
            }
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
     *  @brief Moves active node pointer to node before active node
    */
    void Previous(){
        if (IsActive()){
            active = active->prev;
        }
    }
    /**
     *  @brief Sets last node as active node
    */
    void Last(){
        active = last;
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
            new_node->prev = active;
            active->next = new_node;
            if (new_node->next != nullptr){
                new_node->next->prev = new_node;
            } else {
                last = new_node;
            }
        }
    }
    /**
     *  @brief Inserts node before active node
     *  @param data value saved in new node
    */
    void InsertBefore(T data){
        if (IsActive()){
            Node* new_node = new Node;
            new_node->data = data;
            new_node->next = active;
            new_node->prev = active->prev;
            active->prev = new_node;
            if (new_node->prev != nullptr){
                new_node->prev->next = new_node;
            } else {
                first = new_node;
            }
        }
    }
    /**
     *  @brief Deletes node after active node
    */
    void DeleteAfter(){
        if (IsActive()){
            if (active->next != nullptr){
                Node* tmp = active->next;
                active->next = tmp->next;
                if (active->next == nullptr){
                    last = active;
                } else {
                    active->next->prev = active;
                }
                delete tmp;
            }
        }
    }
    /**
     *  @brief Deletes node before active node
    */
    void DeleteBefore(){
        if (IsActive()){
            if (active->prev != nullptr){
                Node* tmp = active->prev;
                active->prev = tmp->prev;
                if (active->prev == nullptr){
                    first = active;
                } else {
                    active->prev->next = active;
                }
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
     *  @brief Reverses doubly linked list
    */
    void Reverse(){
        if (IsActive()){
            First();
            Next();
            Node* tmp = first;
            while(IsActive()){
                tmp->next = active->next;
                active->next = first;
                active->prev = nullptr;
                first->prev = active;
                if (active == last){
                    last = tmp;
                } else {
                    tmp->next->prev = tmp;
                }
                first = active;
                active = tmp->next;
            }
        }
    }
    /**
     *  @brief Destructor of doubly linked list, deletes all nodes
    */
    ~DoublyLinkedList(){
        while(first != nullptr){
            DeleteFirst();
        }
        active = nullptr;
        last = nullptr;
    }
private:
    struct Node{
        T data; // value saved in node
        Node* next; // pointer to previous node
        Node* prev; // pointer to next node
    };
    Node* first;
    Node* last;
    Node* active;
};