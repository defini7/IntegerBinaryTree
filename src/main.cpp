#include "int_binary_tree.hpp"

#include <random>
#include <chrono>
#include <string>

#define EXPLICIT_SWITCH(v) int(!bool(v))

void usage()
{
    std::cout << "Существует 2 дерева, все операции выполняются на выбранном:\n";
    std::cout << "\tinsert [#] - вставляет значение в дерево\n";
    std::cout << "\tprint - выводит дерево в горизонтальном виде\n";
    std::cout << "\tclear - полностью очищает дерево\n";
    std::cout << "\ttraverse [preorder | inorder | postorder | levels] - обходит дерево предварительно, порядково, отложенно или по уровням\n";
    std::cout << "\tremove [duplicates | #] - удаляет дубликаты или удаляет конкретное значение\n";
    std::cout << "\tswitch - переключается на другое дерево\n";
    std::cout << "\tcopy - копирует все элементы из текущего дерева в оставшееся\n";
    std::cout << "\theight - выводит высоту текущего дерева\n";
    std::cout << "\tincrement - увеличивает все значения в текущем дереве на 1\n";
    std::cout << "\texit - выйти из программы\n";
    std::cout << "\tclear - очищает консоль\n";
    std::cout << "\tusage - выводит это" << std::endl;
}

int main()
{
    setlocale(LC_ALL, "ru");

    IntBinaryTree t[2];
    int cursor = 0;

    std::mt19937 mt(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> dist(0, 10);
    
    while (true)
    {
        std::cout << "> ";
        
        std::string s;
        std::getline(std::cin, s);

        std::string cmd[2];

        size_t j = 0;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
                j++;
            else
                cmd[j].append(1, s[i]);
        }

        if (cmd[0] == "push")
        {
            if (cmd[1].empty())
                t[cursor].push(dist(mt));
            else
                t[cursor].push(std::stoi(cmd[1]));
        }
        else if (cmd[0] == "print")
            std::cout << t[cursor] << std::endl;
        else if (cmd[0] == "clear")
            t[cursor].clear();
        else if (cmd[0] == "traverse")
        {
            if (cmd[1] == "preorder") t[cursor].traverse_preorder();
            if (cmd[1] == "inorder") t[cursor].traverse_inorder();
            if (cmd[1] == "postorder") t[cursor].traverse_postorder();
            if (cmd[1] == "levels") t[cursor].traverse_levels();
        }
        else if (cmd[0] == "remove")
        {
            if (cmd[1] == "duplicates")
                t[cursor].remove_duplicates();
            else
                t[cursor].remove(std::stoi(cmd[1]));
        }
        else if (cmd[0] == "switch")
        {
            cursor = EXPLICIT_SWITCH(cursor);
            std::cout << "Переключено на " << cursor << std::endl;
        }
        else if (cmd[0] == "copy")
        {
            int dest = EXPLICIT_SWITCH(cursor);
            t[dest] = t[cursor];
            std::cout << "Скопировано из " << cursor << " в " << dest << std::endl;
        }
        else if (cmd[0] == "height")
            std::cout << t[cursor].get_height() << std::endl;
        else if (cmd[0] == "increment")
            ++t[cursor]; // t[cursor]++;
        else if (cmd[0] == "usage")
            usage();
        else if (cmd[0] == "exit")
            break;
        else if (cmd[0] == "clear")
            system("cls"); // WIN32
        else
            std::cout << "Неизвестная команда" << std::endl;
    }

    return 0;
}
