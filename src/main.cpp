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

    // Случайные тесты

    for (int i = 0; i < 100; i++)
    {
        std::cout << "Тест №" << i + 1 << "\n\n";

        IntBinaryTree t;

        // Вставка

        std::mt19937 mt(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<> dist(0, 10);

        std::cout << "Вставка: ";

        for (int i = 0; i < 10; i++)
        {
            int value = dist(mt);
            t.push(value);
            std::cout << value << ' ';
        }

        std::cout << std::endl;
        //print_sorted(t.root);
        t.print();
        std::cout << std::endl << std::endl;

        // Обход по уровням

        std::cout << "Обход по уровням:\n";
        t.traverse_levels();
        std::cout << std::endl;

        // Удаление дубликатов

        std::cout << "Удаление дубликатов:\n";
        t.remove_duplicates();

        print_sorted(t.root);
        std::cout << std::endl << std::endl;

        // Удаление элемента

        int removed_value = dist(mt);

        std::cout << "Удаление элемента " << removed_value << std::endl;
        t.remove(removed_value);

        print_sorted(t.root);
        std::cout << std::endl << std::endl;
    }
}
