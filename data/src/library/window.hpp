int init_window(const char* title, int flags);

SDL_Texture* load_texture(
        SDL_Renderer* sRenderer,
        SDL_Surface* surface,
        SDL_Texture* texture,
        std::string asset);

int destroy_window(
        SDL_Window* sWindow, SDL_Renderer* sRenderer, SDL_Texture* sTexture);