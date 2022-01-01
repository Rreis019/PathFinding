#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "CPathFind.h"

CPathFind pathFind;



int main(int argc, char const *argv[])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);

	int StartX = 0, StartY = 0, EndX = 0, EndY = 0;
	bool Visualize = false;
	char filename[255];

	printf("Enter filename: ");
	scanf("%s", filename);

	printf("Enter StartPosX: ");
	scanf("%d", &StartX);

	printf("Enter StartPosY: ");
	scanf("%d", &StartY);

	printf("Enter EndPosX: ");
	scanf("%d", &EndX);

	printf("Enter EndPosY: ");
	scanf("%d", &EndY);

	

	printf("Visualize path? (y/n): ");

	char c[10];
	scanf("%s", c);
	if(c[0] == 'y')
		Visualize = true;
	
	LARGE_INTEGER frequency;
    LARGE_INTEGER startTime, endTime;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&startTime);

	pathFind.LoadMap(filename);
	
	std::vector<CAStarNode*> solution = pathFind.FindPath(StartX, StartY, EndX, EndY);

	QueryPerformanceCounter(&endTime);
	float time = (float)(endTime.QuadPart - startTime.QuadPart) / (float)frequency.QuadPart;
	printf("Pathfinding time: %f seconds\n", time);

	if(Visualize)
		pathFind.VisualizePath(solution);
	
	pathFind.FreeMap();
	

	system("pause");
	return 0;
}