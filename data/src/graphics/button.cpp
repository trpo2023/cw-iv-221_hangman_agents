#include "button.hpp"
#include "window.hpp"

Button::Button()
{
}

// Button::~Button(){}

void Button::get_texture()
{
    t = load_texture(sRenderer, s, t, asset);
    tex = t;
}

void Button::draw()
{
    SDL_RenderCopy(sRenderer, tex, &srect, &drect);
}

void Button::update(Mouse& mouse)
{
    if (SDL_HasIntersection(&drect, &mouse.point)) {
        isSelected = true;
    } else {
        isSelected = false;
    }
}