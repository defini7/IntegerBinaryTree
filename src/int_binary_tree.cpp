#include "int_binary_tree.hpp"

#include <cmath>

IntBinaryTree::Node::Node(int value, Node* left, Node* right)
    : value(value), left(left), right(right)
{

}

IntBinaryTree::IntBinaryTree(const IntBinaryTree& tree)
{
    copy(tree);
}

IntBinaryTree::~IntBinaryTree()
{
    clear();
}

IntBinaryTree& IntBinaryTree::operator=(const IntBinaryTree& rhs)
{
    copy(rhs);
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

void IntBinaryTree::print(std::ostream& os) const
{
    print_helper(os, root, 0);
}

void IntBinaryTree::clear()
{
    clear_impl(root);
}

void IntBinaryTree::traverse_preorder()
{
    traverse_preorder_impl(root);
}

void IntBinaryTree::traverse_inorder()
{
    traverse_inorder_impl(root);
}

void IntBinaryTree::traverse_postorder()
{
    traverse_postorder_impl(root);
}

void IntBinaryTree::remove(int value)
{
    remove(root, value);
}

void IntBinaryTree::traverse_levels()
{
    size_t l = 1;
    size_t elements_count = 0;

    while (print_level(root, l++, elements_count))
    {
        std::cout << "- " << elements_count << std::endl;
        elements_count = 0;
    }
}

void IntBinaryTree::copy(const IntBinaryTree& tree)
{
    clear();
    copy_impl(tree.root, root);
}

size_t IntBinaryTree::get_height()
{
    return calculate_height(root);
}

void IntBinaryTree::remove_duplicates()
{
    remove_duplicates_impl(root);
}

IntBinaryTree IntBinaryTree::operator++(int)
{
    IntBinaryTree t(*this);
    traverse_increment();
    return t;
}

IntBinaryTree& IntBinaryTree::operator++()
{
    traverse_increment();
    return *this;
}

void IntBinaryTree::traverse_increment()
{
    traverse_increment_impl(root);
}

bool IntBinaryTree::print_level(Node* node, size_t level, size_t& elements_count) const
{
    if (!node)
        return false;

    if (level == 1)
    {
        std::cout << node->value << ' ';
        elements_count++;
        return true;
    }

    bool left = print_level(node->left, level - 1, elements_count);
    bool right = print_level(node->right, level - 1, elements_count);
    
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
    // Спускаемся до самого левого, пока можем

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

    // Хранит состояние об удалении узла
    bool removed = false;

    if (value == (*node)->value)
    {
        // Нашли value!

        Node* n = *node;

        if (!n->left)
        {
            // Левый узел не существует => записываем на текущее место правый узел,
            // а старый удаляем
            *node = n->right;
            delete n;
        }
        else if (!n->right)
        {
            // Правый узел не существует => записываем на текущее место левый узел,
            // а старый удаляем
            *node = n->left;
            delete n;
        }
        else
        {
            // 2 узла существуют одновременно => находим самый левый узел начиная с текущего,
            // и засовываем его на место текущего

            Node* leftmost = find_leftmost((*node)->right);

            // Сохраняем значение
            n->value = leftmost->value;

            // Удаляем leftmost из дерева
            delete_node(&n->right, leftmost->value);
        }

        removed = true;
    }
    else
    {
        // Не нашли value => продолжаем искать дальше по правилу (<=, >: как в rb деревьях)

        if (value < (*node)->value)
            removed = delete_node(&(*node)->left, value);
        else
            removed = delete_node(&(*node)->right, value);
    }

    return removed;
}

void IntBinaryTree::print_helper(std::ostream& os, Node* node, int level) const
{
    if (!node) return;

    print_helper(os, node->right, level + 1);

    for (int i = 0; i < level; ++i)
    {
        os << "    ";
    }
    os << node->value << std::endl;

    print_helper(os, node->left, level + 1);
}

void IntBinaryTree::traverse_preorder_impl(Node* node) const
{
    if (node != NULL)
    {
        std::cout << node->value << ' ';
        traverse_preorder_impl(node->left);
        traverse_preorder_impl(node->right);
    }
}

void IntBinaryTree::traverse_inorder_impl(Node* node) const
{
    if (node != nullptr)
    {
        traverse_inorder_impl(node->left);
        std::cout << node->value << ' ';
        traverse_inorder_impl(node->right);
    }
}

void IntBinaryTree::traverse_postorder_impl(Node* node) const
{
    if (node != NULL)
    {
        traverse_postorder_impl(node->left);
        traverse_postorder_impl(node->right);
        std::cout << node->value << ' ';
    }
}

void IntBinaryTree::clear_impl(Node* node)
{
    if (!node)
        return;

    clear_impl(node->left);
    clear_impl(node->right);

    delete node;
    node = nullptr;
}

void IntBinaryTree::copy_impl(Node* src, Node*& dst)
{
    if (!src)
        return;

    dst = new Node(src->value);

    copy_impl(src->left, dst->left);
    copy_impl(src->right, dst->right);
}

size_t IntBinaryTree::calculate_height(Node* node) const
{
    if (!node)
        return 0;

    return 1 + std::max(calculate_height(node->left), calculate_height(node->right));
}

void IntBinaryTree::traverse_increment_impl(Node* node) const
{
    if (node != NULL)
    {
        node->value++;
        traverse_increment_impl(node->left);
        traverse_increment_impl(node->right);
    }
}

void IntBinaryTree::remove(Node*& node, int value)
{
    while (delete_node(&node, value));
}

std::ostream& operator<<(std::ostream& os, const IntBinaryTree& tree)
{
    tree.print(os);
    return os;
}
