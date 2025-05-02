#include "int_binary_tree.hpp"

IntBinaryTree::Node::Node(int value, Node* left, Node* right)
    : value(value), left(left), right(right)
{

}

IntBinaryTree::IntBinaryTree(const IntBinaryTree& tree)
{
    // TODO:  опирование дерева из tree в this (нужен operator=)
}

IntBinaryTree::~IntBinaryTree()
{
    // TODO: ¬ызов очистки дерева
}

IntBinaryTree& IntBinaryTree::operator=(const IntBinaryTree& rhs)
{
    // TODO:  опирование из rhs в this (нужен copy)
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
        if (value <= node->value)
        {
            if (node->left)
                node = node->left;
            else
            {
                node->left = new Node(value);
                node = nullptr;
            }
        }
        else
        {
            if (node->right)
                node = node->right;
            else
            {
                node->right = new Node(value);
                node = nullptr;
            }
        }
    }
}

void IntBinaryTree::print()
{
    // TODO: ѕечать дерева
}

void IntBinaryTree::clear()
{
    // TODO: ѕолное очищение дерева
}

int* IntBinaryTree::traverse_preorder(size_t& elements_count)
{
    // TODO: ѕредварительный обход
    // (возвращаетс€ массив int значений в нужном пор€дке,
    // в elements_count сохран€етс€ их кол-во)
    return nullptr;
}

int* IntBinaryTree::traverse_inorder(size_t& elements_count)
{
    // TODO: ѕор€дковый обход
    // (возвращаетс€ массив int значений в нужном пор€дке,
    // в elements_count сохран€етс€ их кол-во)
    return nullptr;
}

int* IntBinaryTree::traverse_postorder(size_t& elements_count)
{
    // TODO: ќтложенный обход
    // (возвращаетс€ массив int значений в нужном пор€дке,
    // в elements_count сохран€етс€ их кол-во)
    return nullptr;
}

void IntBinaryTree::remove(int value)
{
    // TODO: ”даление элементов с конкретным значением
}

IntBinaryTree*** IntBinaryTree::traverse_levels(size_t& levels_count)
{
    return nullptr;
}

void IntBinaryTree::copy(const IntBinaryTree& tree)
{
    // TODO: ѕолное копирование дерева
}

size_t IntBinaryTree::get_height()
{
    // TODO: ¬ычисление высоты дерева,
    // об этом на английском: https://www.baeldung.com/cs/binary-tree-height
    return 0;
}

void IntBinaryTree::remove_clones()
{
    // TODO: убрать одинаковые значени€ из дерева (но оставить один из них),
    // и после удалени€ элементов нужно привести дерево к правильному виду
}

IntBinaryTree IntBinaryTree::operator++(int)
{
    // TODO: ”величить значени€ всех узлов в дереве на 1 (постфиксный вариант)
    return IntBinaryTree();
}

IntBinaryTree& IntBinaryTree::operator++()
{
    // TODO: ”величить значени€ всех узлов в дереве на 1 (префиксный вариант)
    return *this;
}
