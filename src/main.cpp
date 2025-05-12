#include "int_binary_tree.hpp"

#include <random>
#include <chrono>

int main()
{
    setlocale(LC_ALL, "ru");

    // Случайные тесты

    for (int i = 0; i < 10; i++)
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
        t.print();
        std::cout << std::endl << "--------" << std::endl;
        
        // Копирование + инкремента + оператор <<
        
        IntBinaryTree t1 = t;
        
        t1++; ++t1;
        std::cout << t1 << std::endl << std::endl;

        // Обход по уровням

        std::cout << "Обход по уровням:\n";
        t.traverse_levels();
        std::cout << std::endl;

        // Удаление дубликатов

        std::cout << "Удаление дубликатов:\n";
        t.remove_duplicates();

        t.traverse_inorder();
        std::cout << std::endl << std::endl;

        // Высота

        std::cout << "Высота: " << t.get_height() << std::endl;

        // Удаление элемента

        int removed_value = dist(mt);

        std::cout << "Удаление элемента " << removed_value << std::endl;
        t.remove(removed_value);

        t.traverse_inorder();
        std::cout << std::endl << std::endl;
    }

    return 0;
}
