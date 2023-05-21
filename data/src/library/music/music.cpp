#include "../info/info.hpp"
#include "music.hpp"
#include "../../global.hpp"

void music_volume(int onoff_music)
{
    if (onoff_music == 0 && music > 0)
        music = 0;
    else if (onoff_music == 0 && music == 0)
        music = 100;
    else
    {
        info_music_volume();
        char new_music[10];
        std::cin >> new_music;
        if (atoi(new_music)>=0 && atoi(new_music)<= 100)
            music = atoi(new_music);
        else
        {
            std::cout << "Норм число введи, а не это\n";
            free_stdin();
        }
    }
}
void volume_sounds(int onoff_volume)
{
    if (onoff_volume == 0 && volume > 0)
        volume = 0;
    else if (onoff_volume == 0 && volume == 0)
        volume = 100;
    else
    {
        info_volume_sounds();
        char new_volume[10];
        std::cin >> new_volume;
        if (atoi(new_volume)>=0 && atoi(new_volume)<= 100)
            volume = atoi(new_volume);
        else
        {
            std::cout << "Норм число введи, а не это\n";
            free_stdin();
        }
    }
}
