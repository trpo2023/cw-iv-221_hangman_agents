#include "globals.hpp"
#include "window.hpp"

#pragma once

class Mouse {
public:
    SDL_Texture* tex;
    SDL_Rect rect;
    SDL_Rect point;
    SDL_Surface* s;
    std::string asset = "Cursor.bmp";

    Mouse()
    {
        tex = load_texture(sRenderer, s, tex, asset);
        rect.w = 80;
        rect.h = 80;
        point.w = 1;
        point.h = 1;
        SDL_ShowCursor(false);
    }

    void update()
    {
        SDL_GetMouseState(&rect.x, &rect.y);
        point.x = rect.x;
        point.y = rect.y;
    }

    void draw()
    {
        SDL_RenderCopy(sRenderer, tex, NULL, &rect);
    }
};