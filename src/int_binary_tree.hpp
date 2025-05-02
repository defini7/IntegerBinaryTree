#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

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
    
    int* traverse_preorder(size_t& elements_count);
    int* traverse_inorder(size_t& elements_count);
    int* traverse_postorder(size_t& elements_count);

    void remove(int value);
    IntBinaryTree*** traverse_levels(size_t& levels_count);

    void copy(const IntBinaryTree& tree);
    size_t get_height();
    void remove_clones();

    IntBinaryTree operator++(int);
    IntBinaryTree& operator++();

public:
    Node* root = nullptr;

};

#endif
