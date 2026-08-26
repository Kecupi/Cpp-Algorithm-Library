/***********************************************************************************************
    Project: Algorithm Library
    File: doubly_linked_list.hpp
    Date created: 26. 8. 2026
    Last changed: 26. 8. 2026
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

template <typename T>
Class DoublyLinkedList{
public:
    DoublyLinkedList(){
        first = nullptr;
        last = nullptr;
        active = nullptr;
    }
    bool IsActive(){
        return active != nullptr;
    }
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
    T GetFirst(){
        if (first == nullptr){
            throw std::underflow_error("Can't get value of first in empty list");
        }
        return first->data;
    }
    T GetLast(){
        if (last == nullptr){
            throw std::underflow_error("Can't get value of last in empty list");
        }
        return last->data;
    }
    T GetValue(){
        if (IsActive()){
            return active->data;
        }
        throw std::underflow_error("Can't get value of active in inactive list");
    }
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
                last = nullptr;
            }
            delete tmp;
        }
    }
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
            }
            delete tmp;
        }
    }
    void First(){
        active = first;
    }
    void Next(){
        if (IsActive()){
            active = active->next;
        }
    }
    void Previous(){
        if (IsActive()){
            active = active->prev;
        }
    }
    void Last(){
        active = last;
    }
    void SetValue(T data){
        if (IsActive()){
            active->data = data;
        }
    }
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
    int Length(){
        int length = 0;
        First();
        while(IsActive()){
            length++;
            Next();
        }
        return length;
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
}