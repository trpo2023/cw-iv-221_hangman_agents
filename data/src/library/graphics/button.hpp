#include "globals.hpp"
#include "mouse.hpp"

#pragma once

class Button {
public:
    SDL_Texture* tex;
    SDL_Rect srect, drect;
    std::string asset;
    bool isSelected = false;
    SDL_Surface* s;
    SDL_Texture* t;
    wchar_t value;

    Button();
    // virtual ~Button();
    void draw();
    void get_texture();
    void update(Mouse& mouse);
};
