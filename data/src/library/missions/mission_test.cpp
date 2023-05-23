#include "../../global.hpp"
#include "mission.hpp"

#include <sstream>
#include <fstream>
#include <codecvt>

#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <stdio.h>

#include <iostream>
#include <locale>


void mission_1()
{
    setlocale(LC_ALL, "ru");

    char word[] = "shpion";
    char new_word[strlen(word)];

    for (int i = 0; i < sizeof(word)/sizeof(word[0]); i++)
        new_word[i] = '_';
    new_word[sizeof(word)/sizeof(word[0])] = '\0';

    std::cout <<word<<'\n';
    std::cout <<new_word<<'\n';
    int check = 0;
    int health = 8;
    while (check != sizeof(new_word)/sizeof(new_word[0]) && health > 0)
    {
        std::cout << "Введите символ\n";
        char c;
        std::cin >> c;
        free_stdin();
        int w_word = 0;
        for (int i = 0; i < sizeof(new_word)/sizeof(new_word[0]); i++)
        {
            if (word[i] == c && new_word[i] != c)
            {
                check++;
                std::cout << c;
                new_word[i] = c;
                w_word++;
            }
            else
            {
                std::cout << new_word[i];
            }
        }
        if (w_word == 0)
        {
            std::cout << "\nТакого символа нет или уже открыт\n";
            health--;
        }
        std::cout << '\n';
    }
    if (health == 0)
    {
        std::cout << "Вы проиграли!\n";
    }
    else
    {
        std::cout << "Вы угадали!\n";
    }
}

void mission_2()
{
    // setlocale(LC_ALL, "ru");

    // wchar_t word[] = {L'р',L'а',L'з',L'в',L'е',L'д',L'ч',L'и',L'к',L'\0'};

    // wprintf("%ls\n", word);
    setlocale(LC_ALL,"UTF-8");
    std::wcout << L"мы тут\n";
    setlocale(LC_ALL,"C.UTF-8");
    wchar_t str[] = { L'Х', L'е', L'л', L'л', L'о', L'у', L',', L' ', L'в', L'о', L'р', L'л', L'д', L'\0'};
    // wprintf(L"Это есть русский языка: \"%ls\"\n", str);
    std::wcout << L"Это есть русский языка: " << str << '\n';

    int r;
    wchar_t myChar1 = L'Ω';
    setlocale(LC_CTYPE, "");
    r = wprintf(L"char is %lc (%x)\n", myChar1, myChar1);
}