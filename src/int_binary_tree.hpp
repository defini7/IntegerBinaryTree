#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>

class IntBinaryTree
{
public:
    class Node
    {
    public:
        Node(int value, Node* left = nullptr, Node* right = nullptr);

        int value;

        Node* left = nullptr;
        Node* right = nullptr;
    };

public:
    IntBinaryTree() = default;
    IntBinaryTree(const IntBinaryTree& tree);
    ~IntBinaryTree();

    IntBinaryTree& operator=(const IntBinaryTree& rhs);

    void push(int value);
    void print();
    void clear();
    
    void traverse_preorder();
    void traverse_inorder();
    void traverse_postorder();
    void traverse_levels();

    void remove(int value);
    void remove(Node*& start, int value);

    void copy(const IntBinaryTree& tree);
    size_t get_height();
    void remove_duplicates();

    IntBinaryTree operator++(int);
    IntBinaryTree& operator++();

public:
    Node* root = nullptr;

private:
    // Для traverse_levels
    bool print_level(Node* node, size_t level); 

    // Для delete_node
    Node* find_leftmost(Node* start); 
    
    // Для remove и remove_duplicates
    bool delete_node(Node** node, int value); 

    void remove_duplicates_impl(Node* node);

    void print_helper(Node* node, int level);

    void traverse_preorder_impl(Node* node);
    void traverse_inorder_impl(Node* node);
    void traverse_postorder_impl(Node* node);

    void clear_impl(Node* node);
    void copy_impl(Node* src, Node* dst);

};

#endif
