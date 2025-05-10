#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>

// √лавный класс (€вл€етс€ и узлом, и деревом)
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
    bool print_level(Node* node, size_t level); // дл€ traverse_levels
    void remove_duplicates_impl(Node* node); // дл€ remove_duplicates

    Node* find_leftmost(Node* start); // дл€ delete_node
    bool delete_node(Node** node, int value); // дл€ remove и remove_duplicates

};

#endif
