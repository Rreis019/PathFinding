#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <SDL2/SDL.h>
#include <vector>

#include "CWindow.h"
#include "CInput.h"
#include "CGUI.h"
#include "CPathFind.h"

int StartX = -1;
int StartY = -1;
int EndX = -1;
int EndY = -1;

CPathFind pathfind= CPathFind();
std::vector<CAStarNode*> path;
int main(int argc, char *argv[])
{
	pathfind.Init();
	CWindow::Get().Init();
	CWindow::Get().MainLoop();
	pathfind.FreeMap();

	return 0;
}

void DrawGrid()
{
	int PosX = 0, PosY = 0;
	int TotalX = 0, TotalY = 0;
	for(int y = 0 ; y < 20;y++)
	{
		for(int x = 0; x < 20;x++)
		{
			//if is start draw green
			CGUI& gui = CGUI::Get();

			bool IsStart = StartX == x && StartY == y;
			bool IsEnd = EndX == x && EndY == y;

			if(IsStart){
				gui.ButtonColor =  {0,255,0,255};
				gui.ButtonHoverColor = {0,255,0,255};
			}
			else if(IsEnd){	
				gui.ButtonColor =  {255,0,0,255};
				gui.ButtonHoverColor = {255,0,0,255};
			}
			else if(pathfind.map[y][x]->IsPath)
			{
				//purple
				gui.ButtonColor =  {255,0,255,255};
				gui.ButtonHoverColor = {255,0,255,255};
			}

			if(pathfind.map[y][x]->value == 1){
				gui.ButtonColor =  {0,0,0,255};
				gui.ButtonHoverColor = {0,0,0,255};
			}

			if(CGUI::button(PosX + TotalX, PosY + TotalY))
			{
				bool IsStartNotDefined = StartX == -1 && StartY == -1;
				bool IsEndNotDefined = EndX == -1 && EndY == -1;

				//if start is not defined then set start
				if( Input::IsMouseLeftClicked())
				{
					if(IsStartNotDefined && !IsEnd){StartX = x;StartY = y;}
					else if(IsStart) { StartX = -1;StartY = -1;} //if you click twice you remove it
					//if end is not defined then set end
					else if(IsEndNotDefined){EndX = x;EndY = y;}
					else if(IsEnd) { EndX = -1;EndY = -1;} //if you click twice you remove it
				}
				else{
					if(!IsStartNotDefined && !IsEndNotDefined && !IsStart && !IsEnd)
					{
						if(Input::IsMouseLeftDown()){pathfind.map[y][x]->value = 1;}
						else if(Input::IsMouseRightDown()){pathfind.map[y][x]->value = 0;}
					}
				}


			}

			TotalX += CGUI::Get().ButtonWidth;
			//back color to normal
			gui.ButtonColor =  {255,255,255,255};
			gui.ButtonHoverColor = {233,233,233,255};
		}
		TotalX = 0;
		TotalY += CGUI::Get().ButtonHeight;
	}
}

void CWindow::Render()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);


	DrawGrid();

	if(Input::IsMouseLeftClicked() || Input::IsMouseRightClicked())
		if(StartX != -1 && StartY != -1 && EndX != -1 && EndY != -1)
		{
			
			path = pathfind.FindPath(StartX,StartY,EndX,EndY);
		}
			

	SDL_RenderPresent(renderer);
}
