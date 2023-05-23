#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <unistd.h>
#include <clocale>

#include <ctest.h>
#include <library/strings.hpp>
#include <library/window.hpp>

SDL_Renderer *sRenderer = 0;
SDL_Window *sWindow = 0;

CTEST(window, init_window_false)
{
    sRenderer = nullptr;
    const char *title = NULL;
    int flags = 0;
    int expected = -1;
    int real = init_window(title, flags);

    ASSERT_EQUAL(expected, real);
}

CTEST(window, init_window_true)
{
    const char *title = "wow";
    int flags = 4;
    int expected = 0;
    int real = init_window(title, flags);

    ASSERT_EQUAL(expected, real);
}

CTEST(window, load_texture_false)
{
    SDL_Texture *example = 0;
    SDL_Surface *sur = 0;
    std::string asset = "easease";
    example = load_texture(sRenderer, sur, example, asset);
    
    ASSERT_NULL(example);
}

CTEST(window, window_destroy)
{
    SDL_Texture *tex = 0;
    SDL_Window *win = 0;
    int exp = 0;
    int real = destroy_window(win, sRenderer, tex);

    ASSERT_EQUAL(exp, real);
}