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
    void Insert(T key, S value){
        Node* current = root;
        Node* balance_node = nullptr;
        if (root == nullptr){
            root = Create_Node(key, value);
            return;
        }
        while (true){
            if (key > current->key){
                if (current->right = nullptr){
                    current->right = Create_Node(key, value);
                    Balance(balance_node);
                    return;
                } else {
                    balance_node = current;
                    current = current->right;
                }
            } else if (key < current->key){
                if (current->left = nullptr){
                    current->left = Create_Node(key, value);
                    Balance(balance_node);
                    return;
                } else {
                    balance_node = current;
                    current = current->left;
                }
            } else {
                current->value = value;
                return;
            }
        }
    }
    
    /**
     *  @brief Returns pointer containing value of node based on key
     *  @param key key of node containing value
     *  @return pointer to value if found, nullptr if not present
    */
    const S* Search(T key){
        Node* tmp = root;
        while (tmp != nullptr){
            if (tmp->key == key){
                return &(tmp->value);
            } else if (tmp->key > key){
                tmp = tmp->right;
            } else if (tmp->key < key){
                tmp = tmp->left;
            }
        }
        return nullptr;
    }

    /**
     *  @brief Function for deleting nodes
     *  @param key Key of node to be deleted
    */
    void Delete(T key){
        if (root == nullptr){
            return;
        }
        Node* current = root;
        Node* prev = nullptr;
        bool left = false;
        while (current != nullptr){
            if (current->key > key){
                prev = current;
                current = current->left;
                left = true;
            } else if (current->key < key){
                prev = current;
                current = current->right;
                left = false;
            } else {
                if (current->left == nullptr && current->right == nullptr){
                    if (prev == nullptr){
                        root = nullptr;
                    } else {
                        if (left){
                            prev->left = nullptr;
                        } else {
                            prev->right = nullptr;
                        }
                    }
                } else (current->left == nullptr){
                    if (prev == nullptr){
                        root = root->right;
                    } else {
                        if (left){
                            prev->left = current->right;
                        } else {
                            prev->right = current->right;
                        }
                    }
                } else (current->right == nullptr){
                    if (prev == nullptr){
                        root = root->left;
                    } else {
                        if (left){
                            prev->left = current->left;
                        } else {
                            prev->right = current->left;
                        }
                    }
                } else {
                    Node* help = prev->left;
                    Node* help_prev = nullptr;
                    while(help->right != nullptr){
                        help_prev = help;
                        help = help->right;
                    }
                    if (help_prev == nullptr){

                    } else {
                        help_prev->right = nullptr;
                        help->right = current->right;
                        if (left){
                            prev->left = help;
                        } else {
                            prev->right = help;
                        }
                    }
                }
                delete current;
                Balance();
                return;
            }
        }
        return;
    }


private:
    /**
     *  @brief Private function for balancing the tree)
     *  @param parent_node Parent of the node on whose children was performated operation
    */
    void Balance(Node* parent_node){
        if (parent_node == nullptr){
            return;
        }
        int height = std::max(Max_Height(parent_node->left), Max_Height(parent_node->right));
    }

    /**
     *  @brief Returns nodes balance factor
     *  @param node_ptr Node whose balance is to be returned
     *  @return Balance factor, -1 if nullptr
    */
    int Get_Balance(Node* node_ptr){
        if (node_ptr == nullptr){
            return -1;
        }
        return Get_Height(node_ptr->right) - Get_Height(node_ptr->left);
    }

    /**
     *  @brief Sets height to max height of node children
     *  @param node_ptr Node whose height will be changed
    */
    void Max_Height(Node* node_ptr){
        if (node_ptr == nullptr){
            return;
        }
        node_ptr->height = 1 + std::max(Get_Height(node_ptr->left), Get_Height(node_ptr->right));
    }


    /**
     *  @brief Creates tree nodes
     *  @param key Key of node
     *  @param value Value to be save inside node
     *  @return Node pointer on success, nullptr if allocation fails
    */
    Node* Create_Node(T key, S value){
        Node* new_node = new Node;
        new_node->key = key;
        new_node->value = value;
        new_node->balance = 0;
        new_node->left = nullptr;
        new_node->right = nullptr;
        return new_node;
    }

    struct Node{
        T key;          /**< Key used for searching tree */
        S value;        /**< Value saved in node */
        int height;     /**< Max height of node */
        Node* left;     /**< Left child node */
        Node* right;    /**< Right child node */
    }
    Node* root;         /**< Root of the tree */
}