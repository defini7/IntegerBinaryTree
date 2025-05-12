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
    void print(std::ostream& os = std::cout) const;
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

    friend std::ostream& operator<<(std::ostream& os, const IntBinaryTree& tree);

    void traverse_increment();

public:
    Node* root = nullptr;

private:
    // Для traverse_levels
    bool print_level(Node* node, size_t level) const; 

    // Для delete_node
    static Node* find_leftmost(Node* start); 
    
    // Для remove и remove_duplicates
    bool delete_node(Node** node, int value); 

    void remove_duplicates_impl(Node* node);

    void print_helper(std::ostream& os, Node* node, int level) const;

    void traverse_preorder_impl(Node* node) const;
    void traverse_inorder_impl(Node* node) const;
    void traverse_postorder_impl(Node* node) const;

    void clear_impl(Node* node);
    void copy_impl(Node* src, Node*& dst);

    size_t calculate_height(Node* node) const;

    void traverse_increment_impl(Node* node) const;

};

#endif
