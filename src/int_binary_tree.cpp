#include "int_binary_tree.hpp"

#include <cmath>

IntBinaryTree::Node::Node(int value, Node* left, Node* right)
    : value(value), left(left), right(right)
{

}

IntBinaryTree::IntBinaryTree(const IntBinaryTree& tree)
{
    // TODO: скопировать дерево из tree в this (вызвать copy)
}

IntBinaryTree::~IntBinaryTree()
{
    // TODO: удалить все узлы
}

IntBinaryTree& IntBinaryTree::operator=(const IntBinaryTree& rhs)
{
    // TODO: скопировать из rhs в this (вызвать copy)
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
    // TODO: вывести дерево в консоль
}

void IntBinaryTree::clear()
{
    // TODO: удалить все узлы
}

void IntBinaryTree::traverse_preorder()
{
    // TODO: предварительный обход
}

void IntBinaryTree::traverse_inorder()
{
    // TODO: порядковый обход
}

void IntBinaryTree::traverse_postorder()
{
    // TODO: отложенный обход
}

void IntBinaryTree::remove(int value)
{
    remove(root, value);
}

void IntBinaryTree::traverse_levels()
{
    size_t l = 1;

    while (print_level(root, l++))
        std::cout << std::endl;
}

void IntBinaryTree::copy(const IntBinaryTree& tree)
{
    // TODO: скопировать из tree в this
}

size_t IntBinaryTree::get_height()
{
    // TODO: получить высоту дерева
    return 0;
}

void IntBinaryTree::remove_duplicates()
{
    remove_duplicates_impl(root);
}

IntBinaryTree IntBinaryTree::operator++(int)
{
    // TODO: увеличить все значения в дереве на 1
    return IntBinaryTree();
}

IntBinaryTree& IntBinaryTree::operator++()
{
    // TODO: увеличить все значения в дереве на 1
    return *this;
}

bool IntBinaryTree::print_level(Node* node, size_t level)
{
    if (!node)
        return false;

    if (level == 1)
    {
        std::cout << node->value << ' ';
        return true;
    }

    bool left = print_level(node->left, level - 1);
    bool right = print_level(node->right, level - 1);
    
    return left || right;
}

void IntBinaryTree::remove_duplicates_impl(Node* node)
{
    // TODO: удалить дубликаты
    // Можно и нужно задействовать delete_node
}

bool IntBinaryTree::delete_node(Node** node, int value)
{
    // TODO: искать узлы с value, чтобы удалить, начиная с node, и
    // вернуть true, если что-то удалили
}

void IntBinaryTree::remove(Node*& node, int value)
{
    // TODO: удалить все узлы с value
    while (delete_node(&node, value));
}
