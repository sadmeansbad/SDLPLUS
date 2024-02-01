#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <iostream>
#include "SPLUS_draw.h"

inline int MouseX, MouseY;

class NewButton{
    private:
    SDL_Renderer * buttons_renderer;  
    short buttons_x, buttons_y, buttons_width, buttons_height; 
    Uint8 buttons_Red, buttons_Green, buttons_Blue, buttons_HoverRed, buttons_HoverGreen, buttons_HoverBlue;
    SDL_Event buttons_event;

    public:

    void Setup(SDL_Renderer * local_renderer, SDL_Event &local_event, short lx, short ly, short lwidth, short lheight, Uint8 lRed, Uint8 lGreen, Uint8 lBlue, Uint8 lHoverRed, Uint8 lHoverGreen, Uint8 lHoverBlue){
        buttons_renderer=local_renderer;
        buttons_event=local_event ;
        buttons_x=lx;
        buttons_y=ly;
        buttons_width=lwidth;
        buttons_height=lheight;
        buttons_Red=lRed;
        buttons_Green=lGreen;
        buttons_Blue=lBlue;
        buttons_HoverRed=lHoverRed;
        buttons_HoverGreen=lHoverGreen;
        buttons_HoverBlue=lHoverBlue;
        }

    bool Hover(){
        //SDL_GetMouseState(&MouseX, &MouseY);
        if(MouseX >= buttons_x && MouseX <= buttons_x+buttons_width && MouseY >= buttons_y && MouseY <= buttons_y+buttons_height) return true;
        else return false;
        }

    bool Pressed(){
        if(Hover()&&buttons_event.button.button==SDL_BUTTON_LEFT) return true;
        else return false;
    }

    void Draw(){
        if(!Hover()) DrawRect(buttons_renderer, buttons_x, buttons_y, buttons_width, buttons_height, buttons_Red,buttons_Green,buttons_Blue);
        else DrawRect(buttons_renderer, buttons_x, buttons_y, buttons_width, buttons_height, buttons_HoverRed,buttons_HoverGreen,buttons_HoverBlue);
    }
};