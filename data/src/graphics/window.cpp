#include "window.hpp"
#include "button.hpp"
#include "globals.hpp"
#include "mouse.hpp"

SDL_Window* sWindow = 0;
SDL_Renderer* sRenderer = 0;

int init_window(
        const char* title, int flags) // Функция инициализации окна (завершено)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
        sWindow = SDL_CreateWindow(
                title, 0, 0, 1600, 900, flags); // Создание окна
        if (sWindow != 0) {
            sRenderer = SDL_CreateRenderer(
                    sWindow,
                    -1,
                    SDL_RENDERER_ACCELERATED
                            | SDL_RENDERER_PRESENTVSYNC); // Рендер окна
            if (sRenderer == nullptr) {
                std::cout << "SDL_CreateRender: " << SDL_GetError()
                          << std::endl;
                return -1;
            }
        } else {
            std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
            return -1;
        }
    }
    return 0;
}

SDL_Texture* load_texture(
        SDL_Renderer* sRenderer,
        SDL_Surface* surface,
        SDL_Texture* texture,
        std::string asset) // Загрузка текстуры (завершено)
{
    std::string path = "/home/egor/cw-iv-221_hangman_agents/assets/";
    path = path + asset;
    surface = SDL_LoadBMP(path.c_str());
    if (surface == nullptr) {
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    texture = SDL_CreateTextureFromSurface(sRenderer, surface);

    SDL_FreeSurface(surface);
    if (texture == nullptr) {
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError()
                  << std::endl;
        return nullptr;
    }
    return texture;
}

int destroy_window(
        SDL_Window* sWindow,
        SDL_Renderer* sRenderer,
        SDL_Texture* sTexture) // Уничтожение окна (завершено)
{
    SDL_DestroyTexture(sTexture);
    SDL_DestroyRenderer(sRenderer);
    SDL_DestroyWindow(sWindow);
    return 0;
}

int main()
{
    SDL_Surface* sSurface = 0;
    SDL_Texture* sTexture = 0;

    init_window("Hangman: Agents", SDL_WINDOW_SHOWN);

    Mix_Init(0);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 4, 2048);
    Mix_Music* menu_music = Mix_LoadMUS(
            "/home/egor/cw-iv-221_hangman_agents/assets/Menu_music.mp3");
    if (!menu_music) {
        std::cout << "Music Error: " << Mix_GetError() << std::endl;
    }
    Mix_Chunk* button_click = Mix_LoadWAV(
            "/home/egor/cw-iv-221_hangman_agents/assets/Button_Click.mp3");
    if (!button_click) {
        std::cout << "Sound Error: " << Mix_GetError() << std::endl;
    }

    Mix_PlayMusic(menu_music, -1);

    std::string asset = "Menu.bmp";
    SDL_Rect background;
    background.x = 0;
    background.y = 0;
    background.w = 1600;
    background.h = 900;
    sTexture = load_texture(sRenderer, sSurface, sTexture, asset);

    Button PlayButton;
    PlayButton.asset = "Play.bmp";
    PlayButton.get_texture();
    PlayButton.srect.h = 300;
    PlayButton.srect.w = 600;
    PlayButton.srect.x = 0;
    PlayButton.srect.y = 0;
    PlayButton.drect.h = 100;
    PlayButton.drect.w = 300;
    PlayButton.drect.x = 1600 / 2 - PlayButton.drect.w / 2;
    PlayButton.drect.y = 200;

    Button OptionsButton;
    OptionsButton.asset = "Options.bmp";
    OptionsButton.get_texture();
    OptionsButton.srect.h = 300;
    OptionsButton.srect.w = 600;
    OptionsButton.srect.x = 0;
    OptionsButton.srect.y = 0;
    OptionsButton.drect.h = 100;
    OptionsButton.drect.w = 300;
    OptionsButton.drect.x = 1600 / 2 - OptionsButton.drect.w / 2;
    OptionsButton.drect.y = 350;

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

    Mouse mouse;

    SDL_Event event;
    bool quit = false;
    while (!quit) {
        mouse.update();
        PlayButton.update(mouse);
        OptionsButton.update(mouse);
        ExitButton.update(mouse);
        if (SDL_WaitEvent(&event) == 1) {
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        if (PlayButton.isSelected == true) {
                            std::cout << "Start the game!\n";
                            Mix_PlayChannel(-1, button_click, 0);
                            while (!quit) {
                                mouse.update();
                                if (SDL_WaitEvent(&event) == 1) {
                                    while (SDL_PollEvent(&event)) {
                                        if (event.type == SDL_QUIT) {
                                            quit = true;
                                            break;
                                        }
                                    }
                                }
                                SDL_RenderClear(sRenderer);
                                SDL_RenderCopy(
                                        sRenderer, sTexture, NULL, &background);
                                mouse.draw();
                                SDL_RenderPresent(sRenderer);
                            }
                            break;
                        }
                        if (OptionsButton.isSelected == true) {
                            std::cout << "Open the options!\n";
                            Mix_PlayChannel(-1, button_click, 0);
                            break;
                        }
                        if (ExitButton.isSelected == true) {
                            std::cout
                                    << "Exit the game! Good luck, bastard :>\n";
                            Mix_PlayChannel(-1, button_click, 0);
                            quit = true;
                            return 0;
                        }
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

    destroy_window(sWindow, sRenderer, sTexture);
    SDL_Quit();
    return 0;
}