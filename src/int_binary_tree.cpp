#include "int_binary_tree.hpp"

IntBinaryTree::IntBinaryTree(int value = 0, IntBinaryTree* left = nullptr, IntBinaryTree* right = nullptr)
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
    // TODO: ����������� �� rhs � this (����� clear)
    return *this;
}

void IntBinaryTree::add_element(int value)
{
    // TODO: ���������� value � ������
}

void IntBinaryTree::print()
{
    // TODO: ������ ������
}

void IntBinaryTree::clear()
{
    // TODO: ������ �������� ������
}

int* IntBinaryTree::traverse_preorder(size_t& elements_count)
{
    // TODO: ��������������� �����
    // (������������ ������ int �������� � ������ �������,
    // � elements_count ����������� �� ���-��)
    return nullptr;
}

int* IntBinaryTree::traverse_inorder(size_t& elements_count)
{
    // TODO: ���������� �����
    // (������������ ������ int �������� � ������ �������,
    // � elements_count ����������� �� ���-��)
    return nullptr;
}

int* IntBinaryTree::traverse_postorder(size_t& elements_count)
{
    // TODO: ���������� �����
    // (������������ ������ int �������� � ������ �������,
    // � elements_count ����������� �� ���-��)
    return nullptr;
}

void IntBinaryTree::remove(int value)
{
    // TODO: �������� ��������� � ���������� ���������
}

IntBinaryTree*** IntBinaryTree::traverse_levels(size_t& levels_count)
{
    // TODO: ����� ������ �� �������; �������, ����� ������������ BFS (Breadth First Search)
    // (�� ������ ������������ ������ � �������� � ����������� �� ���� (�� ����� ��������� ����� �����),
    // � levels_count ����������� ���-�� ���� �������)
    return nullptr;
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

IntBinaryTree IntBinaryTree::operator--(int)
{
    // TODO: ��������� �������� ���� ����� � ������ �� 1 (����������� �������)
    return IntBinaryTree();
}

IntBinaryTree& IntBinaryTree::operator--()
{
    // TODO: ��������� �������� ���� ����� � ������ �� 1 (���������� �������)
    return *this;
}
