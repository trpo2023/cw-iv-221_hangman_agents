#include "library/globals.hpp"
#include "library/button.hpp"
#include "library/mouse.hpp"
#include "library/window.hpp"
#include "library/strings.hpp"

SDL_Window* sWindow = 0;
SDL_Renderer* sRenderer = 0;

int main()
{
    srand(time(NULL));
    setlocale(LC_CTYPE ,"rus");
    wchar_t *dictionary = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя";

    SDL_Surface* sSurface = 0;
    SDL_Texture* sTexture = 0;

    std::string asset_path, temp;
    init_window("Hangman: Agents", SDL_WINDOW_SHOWN);

    Mix_Init(0);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 4, 2048);
    temp = get_path(asset_path, "Menu_music.mp3");
    Mix_Music* menu_music = Mix_LoadMUS(
            temp.c_str());
    if (!menu_music) {
        std::cout << "Music Error: " << Mix_GetError() << std::endl;
    }

    temp = get_path(asset_path, "Campaign_music.mp3");
    Mix_Music *campaign_music = Mix_LoadMUS(temp.c_str());
    if (!campaign_music) {
        std::cout << "Music Error: " << Mix_GetError() << std::endl;
    }

    temp = get_path(asset_path, "Bad_end.mp3");
    Mix_Music *bad_end = Mix_LoadMUS(temp.c_str());
    if (!bad_end) {
        std::cout << "Music Error: " << Mix_GetError() << std::endl;
    }

    temp = get_path(asset_path, "Good_end.mp3");
    Mix_Music *good_end = Mix_LoadMUS(temp.c_str());
    if (!good_end) {
        std::cout << "Music Error: " << Mix_GetError() << std::endl;
    }
    
    temp = get_path(asset_path, "Button_Click.mp3");
    Mix_Chunk* button_click = Mix_LoadWAV(
            temp.c_str());
    if (!button_click) {
        std::cout << "Sound Error: " << Mix_GetError() << std::endl;
    }

    temp = get_path(asset_path, "Click_letter.mp3");
    Mix_Chunk* letter_click = Mix_LoadWAV(
            temp.c_str());
    if (!letter_click) {
        std::cout << "Sound Error: " << Mix_GetError() << std::endl;
    }

    std::string asset = "Menu.bmp";
    SDL_Rect background;
    background.x = 0;
    background.y = 0;
    background.w = 1600;
    background.h = 900;
    sTexture = load_texture(sRenderer, sSurface, sTexture, asset);

    std::string asset_dead = "dead.bmp";
    SDL_Rect dead;
    SDL_Texture *dead_t = 0;
    dead.x = 0;
    dead.y = 0;
    dead.w = 1600;
    dead.h = 900;
    dead_t = load_texture(sRenderer, sSurface, dead_t, asset_dead);

    std::string asset_found = "Found.bmp";
    SDL_Rect found;
    SDL_Texture *found_t = 0;
    found.y = 8;
    found.w = 90;
    found.h = 90;
    found_t = load_texture(sRenderer, sSurface, found_t, asset_found);

    std::string asset_win = "Win.bmp";
    SDL_Rect win;
    SDL_Texture *win_t = 0;
    win.x = 400;
    win.y = 50;
    win.w = 800;
    win.h = 600;
    win_t = load_texture(sRenderer, sSurface, win_t, asset_win);

    SDL_Rect stages[8];
    SDL_Texture *stages_t[8];
    std::string asset_stage;
    for (int i = 0; i < 8; i++)
    {
        asset_stage = std::to_string(i + 1) + "s.bmp";
        stages[i].x = 450;
        stages[i].y = 80;
        stages[i].w = 600;
        stages[i].h = 600;
        stages_t[i] = load_texture(sRenderer, sSurface, stages_t[i], asset_stage);
    }

    SDL_Rect letter_on[33];
    SDL_Texture *letter_t[33];
    std::string asset_letter;
    for (int i = 0; i < 33; i++)
    {
        asset_letter = std::to_string(i + 1) + ".bmp";
        letter_on[i].x = 0;
        letter_on[i].y = 10;
        letter_on[i].w = 80;
        letter_on[i].h = 80;
        letter_t[i] = load_texture(sRenderer, sSurface, letter_t[i], asset_letter);
    }

    Button PlayButton;
    PlayButton.asset = "Play.bmp";
    PlayButton.get_texture();
    PlayButton.srect.h = 100;
    PlayButton.srect.w = 300;
    PlayButton.srect.x = 0;
    PlayButton.srect.y = 0;
    PlayButton.drect.h = 100;
    PlayButton.drect.w = 300;
    PlayButton.drect.x = 1600 / 2 - PlayButton.drect.w / 2;
    PlayButton.drect.y = 200;

    Button OptionsButton;
    OptionsButton.asset = "Options.bmp";
    OptionsButton.get_texture();
    OptionsButton.srect.h = 100;
    OptionsButton.srect.w = 300;
    OptionsButton.srect.x = 0;
    OptionsButton.srect.y = 0;
    OptionsButton.drect.h = 100;
    OptionsButton.drect.w = 300;
    OptionsButton.drect.x = 1600 / 2 - OptionsButton.drect.w / 2;
    OptionsButton.drect.y = 350;

    Button ContinueButton;
    ContinueButton.asset = "Play.bmp";
    ContinueButton.get_texture();
    ContinueButton.srect.h = 100;
    ContinueButton.srect.w = 300;
    ContinueButton.srect.x = 0;
    ContinueButton.srect.y = 0;
    ContinueButton.drect.h = 100;
    ContinueButton.drect.w = 300;
    ContinueButton.drect.x = 1600 / 2 - ContinueButton.drect.w / 2;
    ContinueButton.drect.y = 600;

    Button BackButton;
    BackButton.asset = "Play.bmp";
    BackButton.get_texture();
    BackButton.srect.h = 100;
    BackButton.srect.w = 300;
    BackButton.srect.x = 0;
    BackButton.srect.y = 0;
    BackButton.drect.h = 100;
    BackButton.drect.w = 300;
    BackButton.drect.x = 1600 / 2 - BackButton.drect.w / 2;
    BackButton.drect.y = 750;
    
    Button ExitButton;
    ExitButton.asset = "Exit.bmp";
    ExitButton.get_texture();
    ExitButton.srect.h = 300;
    ExitButton.srect.w = 600;
    ExitButton.srect.x = 0;
    ExitButton.srect.y = 0;
    ExitButton.drect.h = 100;
    ExitButton.drect.w = 300;
    ExitButton.drect.x = 1600 / 2 - ExitButton.drect.w / 2;
    ExitButton.drect.y = 500;

    Button Letters[33];
    for (int i = 0; i < 33; i++)
    {
        std::string temp = std::to_string(i + 1) + ".bmp";
        Letters[i].asset = temp;
        Letters[i].get_texture();
        Letters[i].srect.h = 80;
        Letters[i].srect.w = 80;
        Letters[i].srect.x = 0;
        Letters[i].srect.y = 0;
        Letters[i].drect.h = 80;
        Letters[i].drect.w = 80;
        Letters[i].chosed = false;
        Letters[i].value = dictionary[i];
        if (i < 11)
        {
            Letters[i].drect.x = 250 + i * 100;
            Letters[i].drect.y = 610;
        }
        if (i >= 11 && i < 22)
        {
            Letters[i].drect.x = 250 + (i - 11) * 100;
            Letters[i].drect.y = 710;
        }
        if (i >= 22)
        {
            Letters[i].drect.x = 250 + (i - 22) * 100;
            Letters[i].drect.y = 810;
        }
    }

    Mouse mouse;

    SDL_Event event;
    bool menu = false;
    bool quit_menu = false;
    bool quit_game = false;
    bool campaign = false;
    bool ending = false;
    bool volume_check = false;
    int volume = 50;
    int false_choice = 0;
    int true_choice = 0;

    wchar_t *word[5] = {L"агент", L"шпион", L"нож", L"альянс", L"канцлер"};
    int word_choose = 0;
    int len_word;
        
    while (!quit_menu) {
        quit_game = false;
        ending = false;
        if (!menu)
        {
            Mix_PlayMusic(menu_music, -1);
            Mix_VolumeMusic(volume);
            menu = true;
        }   
        mouse.update();
        PlayButton.update(mouse);
        OptionsButton.update(mouse);
        ExitButton.update(mouse);
        Mix_VolumeChunk(button_click, volume);
        Mix_VolumeChunk(letter_click, volume);
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                quit_menu = true;                                
                break;
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    if (PlayButton.isSelected == true) {
                        std::cout << "Start the game!\n";
                        Mix_PlayChannel(-1, button_click, 0);
                        word_choose = rand() % 5;
                        len_word = wcslen(word[word_choose]);
                        while (!quit_game) {
                            int contact[33];
                            if (!campaign)
                            {
                                Mix_HaltMusic();
                                Mix_PlayMusic(campaign_music, -1);
                                Mix_VolumeMusic(volume);
                                campaign = true;
                            }
                            mouse.update();
                            BackButton.update(mouse);
                            ContinueButton.update(mouse);
                            for (int i = 0; i < 33; i++)
                            {
                                Letters[i].update(mouse);
                            }
                            while (SDL_PollEvent(&event)) {
                                if (event.type == SDL_QUIT) {
                                    quit_game = true;
                                    quit_menu = true;
                                    break;
                                }
                                for (int i = 0; i < 33; i++)
                                {
                                    if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT && Letters[i].isSelected == true && Letters[i].chosed == false && true_choice < len_word && false_choice < 8)
                                    {
                                        for (int z = 0; z < len_word; z++)
                                        {
                                            if (word[word_choose][z] == Letters[i].value)
                                            {
                                                std::cout << "True button clicked!\n";
                                                letter_on[i].x = 100 + z * 100; 
                                                Mix_PlayChannel(-1, letter_click, 0);
                                                Letters[i].chosed = true;
                                                contact[i]++;
                                                true_choice++;
                                            }
                                        }
                                    }
                                    if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT && Letters[i].isSelected == true && Letters[i].chosed == false && true_choice < len_word && false_choice < 8)
                                    {
                                        for (int z = 0; z < len_word; z++)
                                        {
                                            if (word[word_choose][z] != Letters[i].value)
                                            {
                                                std::cout << "False button clicked!\n";
                                                Mix_PlayChannel(-1, letter_click, 0);
                                                Letters[i].chosed = true;
                                                letter_on[i].x = 1600;
                                                false_choice++;
                                                break;
                                            }
                                        }
                                    }
                                } 
                                if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT && ContinueButton.isSelected == true && (false_choice >= 8 || true_choice >= len_word))
                                {
                                    std::cout << "Continue the game!\n";
                                    Mix_PlayChannel(-1, button_click, 0);
                                    Mix_HaltMusic();
                                    false_choice = 0;
                                    true_choice = 0;
                                    campaign = false;
                                    ending = false;
                                    for (int i = 0; i < 33; i++)
                                    {
                                        Letters[i].chosed = false;
                                    }
                                }
                                if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT && BackButton.isSelected == true && (false_choice >= 8 || true_choice >= len_word))
                                {
                                    std::cout << "Back to menu!\n";
                                    Mix_PlayChannel(-1, button_click, 0);
                                    Mix_HaltMusic();
                                    menu = false;
                                    campaign = false;
                                    quit_game = true;
                                    false_choice = 0;
                                    true_choice = 0;
                                    for (int i = 0; i < 33; i++)
                                    {
                                        Letters[i].chosed = false;
                                    }
                                    break;
                                }
                            }
                            SDL_RenderClear(sRenderer);
                            SDL_RenderCopy(sRenderer, sTexture, NULL, &background);
                            if (false_choice < 8 && true_choice < len_word)
                            {
                                SDL_RenderCopy(sRenderer, stages_t[false_choice], NULL, &stages[false_choice]);
                                for (int i = 0; i < 33; i++)
                                { 
                                    if (Letters[i].chosed == false)
                                    {
                                        Letters[i].draw();
                                    }
                                    else
                                    {
                                        SDL_RenderCopy(sRenderer, letter_t[i], NULL, &letter_on[i]);
                                    }
                                }
                                for (int i = 0; i < len_word; i++)
                                {
                                    found.x = 100 + i * 100;
                                    SDL_RenderCopy(sRenderer, found_t, NULL, &found);
                                }
                            }
                            if (false_choice >= 8)
                            {
                                if (!ending)
                                {
                                    Mix_HaltMusic();;
                                    Mix_PlayMusic(bad_end, -1);
                                    Mix_VolumeMusic(volume);
                                    ending = true;
                                }
                                SDL_RenderCopy(sRenderer, dead_t, NULL, &dead);
                                BackButton.draw();
                            }
                            if (true_choice >= len_word)
                            {
                                if (!ending)
                                {
                                    Mix_HaltMusic();;
                                    Mix_PlayMusic(good_end, -1);
                                    Mix_VolumeMusic(volume);
                                    ending = true;
                                }
                                SDL_RenderCopy(sRenderer, win_t, NULL, &win);
                                ContinueButton.draw();
                                BackButton.draw();
                            }
                            mouse.draw();
                            SDL_RenderPresent(sRenderer);
                        }
                        break;
                    }
                    if (OptionsButton.isSelected == true) {
                        std::cout << "Open the options!\n";
                        if (volume_check == false)
                        {
                            volume = 0;
                            Mix_PlayChannel(-1, button_click, 0);
                            volume_check = true;
                            menu = false;
                        }
                        else
                        {
                            volume = 50;
                            Mix_PlayChannel(-1, button_click, 0);
                            volume_check = false;
                            menu = false;
                        }
                        break;
                    }
                    if (ExitButton.isSelected == true) {
                        std::cout << "Exit the game! Good luck, bastard :>\n";
                        Mix_PlayChannel(-1, button_click, 0);
                        quit_game = true;
                        return 0;
                    }
                }
            }
        }
        SDL_RenderClear(sRenderer);
        SDL_RenderCopy(sRenderer, sTexture, NULL, &background);
        PlayButton.draw();
        OptionsButton.draw();
        ExitButton.draw();
        mouse.draw();
        SDL_RenderPresent(sRenderer);
    }
    for (int i = 0; i < 33; i++)
    {
        if (Letters[i].tex != nullptr)
        {
            free(Letters[i].tex);
        }
        if (letter_t[i] != nullptr)
        {
            free(letter_t[i]);
        }
    }
    if (PlayButton.tex != nullptr)
    {
        free(PlayButton.tex);
    }
    if (ContinueButton.tex != nullptr)
    {
        free(ContinueButton.tex);
    }
    if (OptionsButton.tex != nullptr)
    {
        free(OptionsButton.tex);
    }
    if (ExitButton.tex != nullptr)
    {
        free(ExitButton.tex);
    }
    if (BackButton.tex != nullptr)
    {
        free(BackButton.tex);
    }
    for (int i = 0; i < 8; i++)
    {
        if (stages_t != NULL)
        {
            free(stages_t[i]);
        }
    }
    if (dead_t != nullptr)
    {
        free(dead_t);
    }
    if (win_t != nullptr)
    {
        free(win_t);
    }
    if (found_t != nullptr)
    {
        free(found_t);
    }
    if (sTexture != nullptr)
    {
        free(sTexture);
    }
    if (menu_music != nullptr)
    {
        free(menu_music);
    }
    if (campaign_music != nullptr)
    {
        free(campaign_music);
    }
    if (button_click != nullptr)
    {
        free(button_click);
    }
    if (letter_click != nullptr)
    {
        free(letter_click);
    }
    if (good_end != nullptr)
    {
        free(good_end);
    }
    if (bad_end != nullptr)
    {
        free(bad_end);
    }
    destroy_window(sWindow, sRenderer, sTexture);
    SDL_Quit();
    return 0;
}