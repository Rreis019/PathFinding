#include "CSingleton.h"
#include <SDL2/SDL.h>


class Input : public CSingleton<Input>
{
    public:
        int MouseX = 0, MouseY = 0;
        bool MouseLeftDown = false, MouseRightDown = false;
        bool MouseLeftUp = false, MouseRightUp = false;
        void Events(SDL_Event& event);


        static int GetMouseX() { return Input::Get().MouseX; }
        static int GetMouseY() { return Input::Get().MouseY; }
        static bool IsKeyDown(SDL_Scancode key);
        static bool IsKeyUp(SDL_Scancode key);
        static bool IsKeyPressed(SDL_Scancode key);
        static bool IsMouseLeftDown();
        static bool IsMouseRightDown();
        static bool IsMouseLeftClicked() {return Input::Get().MouseLeftUp;}
        static bool IsMouseRightClicked() {return Input::Get().MouseRightUp;}
        void Reset();
    private:

        bool KeysUp[SDL_NUM_SCANCODES] = {false};
        bool KeysDown[SDL_NUM_SCANCODES] = {false};


};
