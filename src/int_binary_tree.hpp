#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

// Описывает узел в дереве 
struct Node
{
    Node(int value = 0, Node* left = nullptr, Node* right = nullptr);

    // Значение узла
    int value;

    // Левый узел
    Node* left;

    // Правый узел
    Node* right;
};

// Класс, представляющий бинарное дерево для int значений
class IntBinaryTree
{
public:
    IntBinaryTree(int value = 0);
    IntBinaryTree(const IntBinaryTree& tree);
    ~IntBinaryTree();

    IntBinaryTree& operator=(const IntBinaryTree& rhs);

    void add_element(int value);
    void print();
    void clear();
    
    int* traverse_preorder(size_t& elements_count);
    int* traverse_inorder(size_t& elements_count);
    int* traverse_postorder(size_t& elements_count);

    void remove(int value);
    Node*** traverse_levels(size_t& levels_count);

    void copy(const IntBinaryTree& tree);
    size_t get_height();
    void remove_clones();

    IntBinaryTree operator++(int);
    IntBinaryTree& operator++();
private:
    // Корень дерева
    Node* m_root = nullptr;

};

#endif
