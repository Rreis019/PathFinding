#include "CWindow.h"
#include <stdio.h>
#include "CInput.h"
void CWindow::Events()
{
	Input::Get().Reset();
    SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
				break;
		}
		Input::Get().Events(event);
	}
}


void CWindow::MainLoop()
{
    while (IsRunning)
    {
		//SDL_SetCursor(SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW));
        clock.Tick(30);
        Events();
        Render();
    }
}

bool CWindow::Init()
{
    SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("A* Pathfinding", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL)
	{
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

    return true;
}



 void CWindow::DrawFilledRectangle(int x, int y, int w, int h, int r, int g, int b, int a)
 {
        SDL_Rect rect = { x, y, w, h };
        SDL_SetRenderDrawColor(renderer, r, g, b, a);
        SDL_RenderFillRect(renderer, &rect);
 }

 void CWindow::DrawRectangle(int x, int y, int w, int h, int thickness ,int r, int g, int b, int a)
 {
    DrawFilledRectangle(x, y, w, thickness, r, g, b, a);
    DrawFilledRectangle(x, y, thickness, h, r, g, b, a);
    DrawFilledRectangle(x + w, y, thickness, h, r, g, b, a);
    DrawFilledRectangle(x, y + h, w + thickness, thickness, r, g, b, a);
 }

 void CWindow::DrawLine(int x1, int y1, int x2, int y2, int r, int g, int b, int a)
 {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
 }