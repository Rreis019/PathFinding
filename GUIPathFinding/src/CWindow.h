#include "CSingleton.h"
#include <SDL2/SDL.h>
#include "CClock.h"
class CWindow : public CSingleton<CWindow>
{
    public:
        bool IsRunning = true;

        bool Init();
        void MainLoop();
        void Render();
        void Events();

        void DrawFilledRectangle(int x, int y, int w, int h, int r, int g, int b, int a);
        void DrawRectangle(int x, int y, int w, int h, int thickness ,int r, int g, int b, int a);
        void DrawLine(int x1, int y1, int x2, int y2, int r, int g, int b, int a);

    private:
        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;
        CClock clock;
};