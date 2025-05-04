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
    // TODO: Полное копирование дерева
}

size_t IntBinaryTree::get_height()
{
    // TODO: Вычисление высоты дерева,
    // об этом на английском: https://www.baeldung.com/cs/binary-tree-height
    return 0;
}

void IntBinaryTree::remove_duplicates()
{
    remove_duplicates_impl(root);
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
    if (!node)
        return;

    // Проходимся по каждому значению в дереве, чтобы проверить на наличие дубликатов
    remove_duplicates_impl(node->left);
    remove_duplicates_impl(node->right);

    // Удаляем все дубликаты и оставляем первое встретившееся значение
    remove(node->left, node->value);
    remove(node->right, node->value);
}

IntBinaryTree::Node* IntBinaryTree::find_leftmost(Node* start)
{
    // Получаем самый левый узел в текущем поддереве

    while (start && start->left)
        start = start->left;

    return start;
}

bool IntBinaryTree::delete_node(Node** node, int value)
{
    if (!(*node))
    {
        // Не нашли value
        return false;
    }

    bool removed = false;

    if (value == (*node)->value)
    {
        // Нашли value!

        Node* n = *node;

        if (!n->left)
        {
            // Нету левого потомка => на текущий узел устанавливаем правого потомка
            // и удаляем узел, который был раньше на данном месте
            *node = n->right;
            delete n;
        }
        else if (!n->right)
        {
            // То же самое, что и для отсутствия левого потомка, только тут нет правого
            *node = n->left;
            delete n;
        }
        else
        {
            // Есть 2 потомка, поэтому берем самый левый узел из правого потомка =>
            // гарантия, что дерево восстановится (этот метод взят из какой-то книжки по информатике)

            Node* leftmost = find_leftmost((*node)->right);

            // Сохраняем его значение
            n->value = leftmost->value;

            // Удаляем leftmost узел из правого потомка
            delete_node(&n->right, leftmost->value);
        }

        removed = true;
    }
    else
    {
        // Ищем в дереве нужное нам значение (так же как производили вставку)

        if (value < (*node)->value)
            removed = delete_node(&(*node)->left, value);
        else
            removed = delete_node(&(*node)->right, value);
    }

    return removed;
}

void IntBinaryTree::remove(Node*& node, int value)
{
    // Пытаемся удалить, пока value в дереве существует
    while (delete_node(&node, value));
}
