/***********************************************************************************************
    Project: Algorithm Library
    File: queue.hpp
    Date created: 27. 8. 2026
    Last changed: 27. 8. 2026
    Author: Stepan Horenek
    
    Description: Impelementation of queue using templates
***********************************************************************************************/
/**
 *  @file queue.hpp
 *  @brief Implementation of queue via templates
 *
 *  Implementation of queue via templates
 *
 *  @author Stepan Horenek
 *  @date 27. 8. 2026
*/

/** 
 *  @brief Implementation of Queue data structure
 *  @tparam T Template for data type of values contained in nodes of stack
*/
template<typename T>
class Queue{
public:
    /**
     *  @brief Initializes Queue class
    */
    Queue(){
        first = nullptr;
        last = nullptr;
    }
    /**
     *  @brief Checks if queue is currently empty
     *  @return true if active, false otherwise
    */
    bool IsEmpty(){
        return first == nullptr;
    }
    /**
     *  @brief Adds value at the end of queue
     *  @param value value to be pushed at the end of queue
    */
    void Add(T value){
        Node* new_node = new Node;
        new_node->data = value;
        new_node->next = nullptr;
        if (IsEmpty()){
            first = new_node;
        } else {
            last->next = new_node;
            last = new_node;
        }
    }
    /**
     *  @brief Returns queue size
     *  @return size of queue
    */
    int Size(){
        int size = 0;
        Node* tmp = first;
        while (tmp != nullptr){
            size++;
            tmp = tmp->next;
        }
        return size;
    }
    /**
     *  @brief Removes node from front of queue
    */
    void Remove(){
        if (!IsEmpty()){
            Node* tmp = first;
            first = first->next;
            if (first == nullptr){
                last = nullptr;
            }
            delete tmp;
        }
    }
    /**
     *  @brief Returns value in node at the front of queue
     *  @return value from first node in queue
    */
    T Front(){
        if (IsEmpty()){
            throw std::out_of_range("Error: Can't get item from empty Queue!");
        }
        return first->data;
    }
    /**
     *  @brief Destructor of queue, deletes all nodes
    */
    ~Queue(){
        while(first != nullptr){
            Remove();
        }
        last = nullptr;
    }
private:
    struct Node{
        T data; // value saved in node
        Node* next; // pointer to next node
    };
    Node* first; // current first node in queue
    Node* last; // last node in queue
}