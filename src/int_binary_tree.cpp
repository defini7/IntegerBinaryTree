#include "int_binary_tree.hpp"

#include <cmath>

IntBinaryTree::Node::Node(int value, Node* left, Node* right)
    : value(value), left(left), right(right)
{

}

IntBinaryTree::IntBinaryTree(const IntBinaryTree& tree)
{
    // TODO: Копирование дерева из tree в this (нужен operator=)
}

IntBinaryTree::~IntBinaryTree()
{
    // TODO: Вызов очистки дерева
}

IntBinaryTree& IntBinaryTree::operator=(const IntBinaryTree& rhs)
{
    // TODO: Копирование из rhs в this (нужен copy)
    return *this;
}

void IntBinaryTree::push(int value)
{
    if (!root)
    {
        root = new Node(value);
        return;
    }

    Node* node = root;

    while (node)
    {
        Node*& test_node = (value <= node->value) ? node->left : node->right;

        if (test_node)
            node = test_node;
        else
        {
            test_node = new Node(value);
            node = nullptr;
        }
    }
}

void IntBinaryTree::print()
{
    // TODO: Печать дерева
}

void IntBinaryTree::clear()
{
    // TODO: Полное очищение дерева
}

void IntBinaryTree::traverse_preorder()
{
    // TODO: Предварительный обход
}

void IntBinaryTree::traverse_inorder()
{
    // TODO: Порядковый обход
}

void IntBinaryTree::traverse_postorder()
{
    // TODO: Отложенный обход
}

void IntBinaryTree::remove(int value)
{
    // TODO: Удаление элементов с конкретным значением
}

void IntBinaryTree::traverse_levels()
{
    size_t l = 1;

    while (print_level(root, l++))
        std::cout << std::endl;
}

void IntBinaryTree::copy(const IntBinaryTree& tree)
{
    // TODO: Полное копирование дерева
}

size_t IntBinaryTree::get_height()
{
    // TODO: Вычисление высоты дерева,
    // об этом на английском: https://www.baeldung.com/cs/binary-tree-height
    return 0;
}

void IntBinaryTree::remove_clones()
{
    // TODO: убрать одинаковые значения из дерева (но оставить один из них),
    // и после удаления элементов нужно привести дерево к правильному виду
}

IntBinaryTree IntBinaryTree::operator++(int)
{
    // TODO: Увеличить значения всех узлов в дереве на 1 (постфиксный вариант)
    return IntBinaryTree();
}

IntBinaryTree& IntBinaryTree::operator++()
{
    // TODO: Увеличить значения всех узлов в дереве на 1 (префиксный вариант)
    return *this;
}

bool IntBinaryTree::print_level(Node* root, size_t level)
{
    if (!root)
        return false;

    if (level == 1)
    {
        std::cout << root->value << ' ';
        return true;
    }

    bool left = print_level(root->left, level - 1);
    bool right = print_level(root->right, level - 1);
    
    return left || right;
}
