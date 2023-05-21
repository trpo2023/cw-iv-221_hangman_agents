#include "global.hpp"
#include "library/info/info.hpp"
#include "library/music/music.hpp"
#include "global.hpp"

int volume = 50;
int music = 50;


void free_stdin()
{
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}
void open_missions(int number)
{
    std::cout << "Выбрана миссия " << number << " mission\n";
}
void open_map()
{
    std::cout << "Какая-то карта\n";
}
void map()
{
    
    open_map();
    while (1)
    {
        info_map();
        int choice_map;
        std::cin >> choice_map;
        if (choice_map > 0 && choice_map < 20)
            open_missions(choice_map);
        else if (choice_map == 21)
            info_map();
        else if (choice_map == 22)
            break;
        else
        {
            std::cout << "Нет такой миссии\n";
            free_stdin();
        }
    }
}

void parameters()
{
    while (1)
    {
        info_parameters();
        int choice;
        std::cin >> choice;

        if (choice == 5)
            break;
        else if (choice == 1)
            volume_sounds(0);
        else if (choice == 2)
            volume_sounds(1);
        else if (choice == 3)
            music_volume(0);
        else if (choice == 4)
            music_volume(1);
        else
        {
            std::cout << "Отладочный вывод 1\n";
            free_stdin();
        }
    }
    
} 

int main()
{
    hello_menu();
    while (1)
    {
        info_menu();
        int i;
        std::cin >> i;
        switch (i)
        {
        case 1:
            std::cout << "Выполняется сцена -> Кампания !\n";
            map();
            break;
        case 2:
            std::cout << "Выполняется сцена -> Настройки!\n";
            parameters();
            break;
        case 3:
            std::cout << "Выполняется сцена -> Выход!\n";
            exit(0);
        case 4:
            info_menu();
            break;
        default:
            std::cout << "Введи нормально!\n";
            free_stdin();
        }
    }
}