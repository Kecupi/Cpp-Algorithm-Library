/***********************************************************************************************
    Project: Algorithm Library
    File: AVL tree.hpp
    Date created: 15. 9. 2026
    Last changed: 1. 10. 2026
    Author: Stepan Horenek
    
    Description: Impelementation of AVL tree using templates
***********************************************************************************************/
/**
 *  @file avl_tree.hpp
 *  @brief Implementation of AVL tree via templates
 *
 *  Implementation of AVL tree via templates
 *
 *  @author Stepan Horenek
 *  @date 15. 9. 2026
*/

/** 
 *  @brief Implementation of AVL tree data structure
 *  @tparam T template type of key inside nodes
 *  @tparam S template type of values inside node
*/
template<typename T, typename S>
class AVL_tree(){
public:
    /**
     *  @brief Initializes AVL_tree class
    */
    AVL_tree(){
        root = nullptr;
    }
    /**
     *  @brief Function for inserting keys with data into tree
     *  @param key Key dictating location of node
     *  @param value Value to be saved inside node
    */
    void Insert(T key, T value){
        Node* new_node = new Node;
        Node* current = root;
        new_node->key = key;
        new_node->value = value;
        new_node->left = nullptr;
        new_node->right = nullptr;
        if (root == nullptr){
            root = new_node;
            return;
        }
        while (true){
            if (new_node->key > current->key){
                if (current->right = nullptr){
                    current->right = new_node;
                    break;
                } else {
                    current = current->right;
                }
            } else if (new_node->key < current->key){
                if (current->left = nullptr){
                    current->left = new_node;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                delete new_node;
                current->value = new_node->value;
                break;
            }
        }
        Balance();
    }

private:
    /**
     *  @brief Private function for balancing the tree
    */
    void Balance(){
        return;
    }

    struct Node{
        T key;          /**< Key used for searching tree */
        S value;        /**< Value saved in node */
        Node* left;     /**< Left child node */
        Node* right;    /**< Right child node */
    }
    Node* root;         /**< Root of the tree */
}