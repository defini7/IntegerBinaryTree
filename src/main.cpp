#include "int_binary_tree.hpp"

#include <random>
#include <chrono>

void print_sorted(IntBinaryTree::Node* node)
{
    if (!node)
        return;

    print_sorted(node->left);
    std::cout << node->value << ' ';
    print_sorted(node->right);
}

int main()
{
    // TODO: Тестирование и демонстрация написанных вами методов

    setlocale(LC_ALL, "ru");

    // Вставка

    IntBinaryTree t;

    std::mt19937 mt/*(std::chrono::system_clock::now().time_since_epoch().count())*/;
    std::uniform_int_distribution<> dist(0, 20);

    std::cout << "Вставка: ";
    
    for (int i = 0; i < 10; i++)
    {
        int value = dist(mt);
        t.push(value);
        std::cout << value << ' ';
    }

    std::cout << std::endl;
    print_sorted(t.root);
    std::cout << std::endl << std::endl;

    std::cout << "Обход по уровням:\n";
    t.traverse_levels();
}
