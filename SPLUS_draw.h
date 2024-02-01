#include <SDL2/SDL.h>

inline void DrawRect(SDL_Renderer * renderer, short x, short y, short width, short height, Uint8 RectRed, Uint8 RectGreen, Uint8 RectBlue)
    {
    SDL_SetRenderDrawColor(renderer, RectRed,RectGreen,RectBlue,255);
    for(int n=0; n != height; n++){
        for(int i=0; i!=width; i++){
            SDL_RenderDrawPoint(renderer, n+x, i+y);
            }
        }
    }