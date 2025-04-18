#include "int_binary_tree.hpp"

IntBinaryTree::IntBinaryTree(int value = 0, IntBinaryTree* left = nullptr, IntBinaryTree* right = nullptr)
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
    // TODO:  опирование из rhs в this (нужен clear)
    return *this;
}

void IntBinaryTree::add_element(int value)
{
    // TODO: ƒобавление value в дерево
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
    // TODO: ќбход дерева по уровн€м; кажетс€, нужно использовать BFS (Breadth First Search)
    // (из метода возвращаетс€ массив с уровн€ми с указател€ми на узлы (не нужно создавать копии узлов),
    // в levels_count сохран€етс€ кол-во этих уровней)
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

IntBinaryTree IntBinaryTree::operator--(int)
{
    // TODO: ”меньшить значени€ всех узлов в дереве на 1 (постфиксный вариант)
    return IntBinaryTree();
}

IntBinaryTree& IntBinaryTree::operator--()
{
    // TODO: ”меньшить значени€ всех узлов в дереве на 1 (префиксный вариант)
    return *this;
}
