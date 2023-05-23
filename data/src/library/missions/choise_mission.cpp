#include "../../global.hpp"
#include "mission.hpp"

void open_missions(int number)
{
    std::cout << "Выбрана миссия " << number << " mission\n";
    switch (number)
    {
    case 1:
        mission_1();
        break;
    case 2:
        mission_2();
        break;
    case 3:
        std::cout << "Пока ничего 3\n";
        break;
    case 4:
        std::cout << "Пока ничего 4\n";
        break;
    case 5:
        std::cout << "Пока ничего 5\n";
        break;
    case 6:
        std::cout << "Пока ничего 6\n";
        break;
    case 7:
        std::cout << "Пока ничего 7\n";
        break;
    case 8:
        std::cout << "Пока ничего 8\n";
        break;
    case 9:
        std::cout << "Пока ничего 9\n";
        break;
    case 10:
        std::cout << "Пока ничего 10\n";
        break;
    case 11:
        std::cout << "Пока ничего 11\n";
        break;
    case 12:
        std::cout << "Пока ничего 12\n";
        break;
    case 13:
        std::cout << "Пока ничего 13\n";
        break;
    case 14:
        std::cout << "Пока ничего 14\n";
        break;
    case 15:
        std::cout << "Пока ничего 15\n";
        break;
    case 16:
        std::cout << "Пока ничего 16\n";
        break;
    case 17:
        std::cout << "Пока ничего 17\n";
        break;
    case 18:
        std::cout << "Пока ничего 18\n";
        break;
    case 19:
        std::cout << "Пока ничего 19\n";
        break;
    case 20:
        std::cout << "Пока ничего 20\n";
        break;
    default:
        break;
    }
}