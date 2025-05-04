#include "int_binary_tree.hpp"

#include <cmath>

IntBinaryTree::Node::Node(int value, Node* left, Node* right)
    : value(value), left(left), right(right)
{

}

IntBinaryTree::IntBinaryTree(const IntBinaryTree& tree)
{
    // TODO: ����������� ������ �� tree � this (����� operator=)
}

IntBinaryTree::~IntBinaryTree()
{
    // TODO: ����� ������� ������
}

IntBinaryTree& IntBinaryTree::operator=(const IntBinaryTree& rhs)
{
    // TODO: ����������� �� rhs � this (����� copy)
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
    // TODO: ������ ������
}

void IntBinaryTree::clear()
{
    // TODO: ������ �������� ������
}

void IntBinaryTree::traverse_preorder()
{
    // TODO: ��������������� �����
}

void IntBinaryTree::traverse_inorder()
{
    // TODO: ���������� �����
}

void IntBinaryTree::traverse_postorder()
{
    // TODO: ���������� �����
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
    // TODO: ������ ����������� ������
}

size_t IntBinaryTree::get_height()
{
    // TODO: ���������� ������ ������,
    // �� ���� �� ����������: https://www.baeldung.com/cs/binary-tree-height
    return 0;
}

void IntBinaryTree::remove_duplicates()
{
    remove_duplicates_impl(root);
}

IntBinaryTree IntBinaryTree::operator++(int)
{
    // TODO: ��������� �������� ���� ����� � ������ �� 1 (����������� �������)
    return IntBinaryTree();
}

IntBinaryTree& IntBinaryTree::operator++()
{
    // TODO: ��������� �������� ���� ����� � ������ �� 1 (���������� �������)
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

    // ���������� �� ������� �������� � ������, ����� ��������� �� ������� ����������
    remove_duplicates_impl(node->left);
    remove_duplicates_impl(node->right);

    // ������� ��� ��������� � ��������� ������ ������������� ��������
    remove(node->left, node->value);
    remove(node->right, node->value);
}

IntBinaryTree::Node* IntBinaryTree::find_leftmost(Node* start)
{
    // �������� ����� ����� ���� � ������� ���������

    while (start && start->left)
        start = start->left;

    return start;
}

bool IntBinaryTree::delete_node(Node** node, int value)
{
    if (!(*node))
    {
        // �� ����� value
        return false;
    }

    bool removed = false;

    if (value == (*node)->value)
    {
        // ����� value!

        Node* n = *node;

        if (!n->left)
        {
            // ���� ������ ������� => �� ������� ���� ������������� ������� �������
            // � ������� ����, ������� ��� ������ �� ������ �����
            *node = n->right;
            delete n;
        }
        else if (!n->right)
        {
            // �� �� �����, ��� � ��� ���������� ������ �������, ������ ��� ��� �������
            *node = n->left;
            delete n;
        }
        else
        {
            // ���� 2 �������, ������� ����� ����� ����� ���� �� ������� ������� =>
            // ��������, ��� ������ ������������� (���� ����� ���� �� �����-�� ������ �� �����������)

            Node* leftmost = find_leftmost((*node)->right);

            // ��������� ��� ��������
            n->value = leftmost->value;

            // ������� leftmost ���� �� ������� �������
            delete_node(&n->right, leftmost->value);
        }

        removed = true;
    }
    else
    {
        // ���� � ������ ������ ��� �������� (��� �� ��� ����������� �������)

        if (value < (*node)->value)
            removed = delete_node(&(*node)->left, value);
        else
            removed = delete_node(&(*node)->right, value);
    }

    return removed;
}

void IntBinaryTree::remove(Node*& node, int value)
{
    // �������� �������, ���� value � ������ ����������
    while (delete_node(&node, value));
}
