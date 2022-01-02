#include "CInput.h"
#include <stdio.h>

void Input::Events(SDL_Event& event)
{
    switch (event.type)
    {
        case SDL_MOUSEMOTION:
            MouseX = event.motion.x;
            MouseY = event.motion.y;
            break;
        case SDL_KEYDOWN:
            KeysDown[event.key.keysym.scancode] = true;
            break;
        case SDL_KEYUP:
            KeysDown[event.key.keysym.scancode] = false;
            KeysUp[event.key.keysym.scancode] = true;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT)
                MouseLeftDown = true;
            else if (event.button.button == SDL_BUTTON_RIGHT)
                MouseRightDown = true;
            break;
        case SDL_MOUSEBUTTONUP:
            if (event.button.button == SDL_BUTTON_LEFT){
                MouseLeftDown = false;
                MouseLeftUp = true;
            }
            else if (event.button.button == SDL_BUTTON_RIGHT){
                MouseRightDown = false;
                MouseRightUp = true;
            }
            break;

    }
}



bool Input::IsKeyDown(SDL_Scancode key)
{
    return Input::Get().KeysDown[key];
}

bool Input::IsKeyUp(SDL_Scancode key)
{
    return Input::Get().KeysUp[key];
}

bool Input::IsKeyPressed(SDL_Scancode key)
 {
        if (Input::Get().KeysDown[key])
        {
            Input::Get().KeysUp[key] = false;
            return true;
        }
        return false;
 }

bool Input::IsMouseLeftDown()
{
    return Input::Get().MouseLeftDown;
}

bool Input::IsMouseRightDown()
{
    return Input::Get().MouseRightDown;
}

void Input::Reset()
{
    MouseLeftUp = false;
    MouseRightUp = false;
}