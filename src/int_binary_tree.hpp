#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>

// Главный класс (является и узлом, и деревом)
class IntBinaryTree
{
public:
    struct Node
    {
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

    void copy(const IntBinaryTree& tree);
    size_t get_height();
    void remove_clones();

    IntBinaryTree operator++(int);
    IntBinaryTree& operator++();

public:
    Node* root = nullptr;

private:
    bool print_level(Node* root, size_t level);

};

#endif
