#include "globals.hpp"
#include "window.hpp"

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