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
    // TODO: �������� ��������� � ���������� ���������
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

void IntBinaryTree::remove_clones()
{
    // TODO: ������ ���������� �������� �� ������ (�� �������� ���� �� ���),
    // � ����� �������� ��������� ����� �������� ������ � ����������� ����
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
