#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <windows.h>


#include "CPathFind.h"
#include "Log.h"

void CPathFind::LoadMap(char* filename)
{
    std::ifstream file { filename , std::ios::in };

    if(!file.is_open())
    {
        DEBUG_PRINT("Error: Could not open file: %s", filename);
        return;
    }

    //get map size
    file >> width >> height;
    DEBUG_PRINT("Map size: %d x %d\n", width, height);



    map = new Map[height];
    for(int i = 0; i < height; i++)
    {
        map[i] = new CAStarNode*[width];
    }


    //read map as int array
    /*
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            int tmp;
            file >> tmp;
            printf("%d,", tmp);
            map[i][j] = new CAStarNode(i,j,tmp);
        }
    }*/


    for(int y = 0 ; y < height;y++)
    {
        for(int x = 0 ; x < width;x++)
        {
            int tmp;
            file >> tmp;
            map[y][x] = new CAStarNode(x,y,tmp);
        }
    }

    file.close();
}	

//Da reset ao mapa para que possa encontrar outro caminho novamente no mesmo mapa
void CPathFind::ResetMap()
{
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            map[j][i]->g = 0;
            map[j][i]->g = 0;
            map[j][i]->g = 0;
            map[j][i]->parent = nullptr;
        }
    }
}

void CPathFind::PrintMap()
{
    if(!DEBUG)
        return;

    for(int y = 0; y< height; y++)
    {  
        for(int x = 0; x < width; x++)
        {
            printf("%d ", map[y][x]->value);
        }
        printf("\n");
    }
}

void CPathFind::FreeMap()
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            delete map[i][j];
        }
        delete[] map[i];
    }
    delete[] map;
}

std::vector<CAStarNode*> CPathFind::GetNeighbors(CAStarNode* currentNode)
{
    std::vector<CAStarNode*> neighbors;

    //left
    if(currentNode->x > 0)
        neighbors.push_back(map[currentNode->y][currentNode->x-1]);

    //right
    if(currentNode->x < width-1)
        neighbors.push_back(map[currentNode->y][currentNode->x+1]);

    //up
    if(currentNode->y > 0)
        neighbors.push_back(map[currentNode->y-1][currentNode->x]);

    //down
    if(currentNode->y < height-1)
        neighbors.push_back(map[currentNode->y+1][currentNode->x]);

    return neighbors;
}



std::vector<CAStarNode*> CPathFind::reconstructPath(CAStarNode* current)
{
    std::vector<CAStarNode*> path;
    
    while(current != NULL)
    {
        path.push_back(current);
        current = current->parent;
    }
    return path;
}

void CPathFind::PushOpen(CAStarNode* node)
{
   // if(node->IsOpen)
     //   return;

    node->IsOpen = true;
    openList.push(node);
}

void CPathFind::PopOpen(CAStarNode* node)
{
    //if(node->IsClosed)
      //  return;

    node->IsOpen = false;
}

std::vector<CAStarNode*> CPathFind::FindPath(int startX, int startY, int endX, int endY)
{
    if(this->width == 0 || this->height == 0)
    {
        DEBUG_PRINT("Error: Map not loaded");
        return std::vector<CAStarNode*>();
    }

    //openlist  clear
    while(!openList.empty()){openList.pop();}
    closedList.clear();


    map[startY][startX]->calculateCost(startX, startY, endX, endY);
    openList.push(map[startY][startX]);
    map[startY][startX]->IsOpen = true;

    CAStarNode* currentNode;
    while (!openList.empty())
    {
        currentNode = openList.top();

        if(currentNode->x == endX && currentNode->y == endY)
        {
            DEBUG_PRINT("Path found\n");
            return reconstructPath(currentNode);
        }
        
        currentNode->IsOpen = false;
        openList.pop();
        
        closedList.push_back(currentNode);
        currentNode->IsClosed = true;

        std::vector<CAStarNode*> neighbors = GetNeighbors(currentNode);

        for(auto neighbor : neighbors)
        {
            bool isInClosedList =  neighbor->IsClosed;//neighbor->isInList(closedList);
            bool isWalkable = map[neighbor->y][neighbor->x]->value == 0;

            if(isInClosedList || !isWalkable)
                continue;

            float tempG = currentNode->g + currentNode->distanceTo(neighbor->x, neighbor->y);

            //if(!neighbor->isInList(openList))
            if(!neighbor->IsOpen)
            {
                openList.push(neighbor);
                neighbor->IsOpen = true;
            }
            else if (tempG >= neighbor->g)
                continue;

            neighbor->g = tempG;
            neighbor->h = neighbor->distanceTo(endX, endY);
            neighbor->f = neighbor->g + neighbor->h;
            neighbor->parent = currentNode;

        }
    }

    DEBUG_PRINT("No path found!\n");
    return std::vector<CAStarNode*>();
}

void CPathFind::VisualizePath(std::vector<CAStarNode*> path)
{
    //loop all map and print value
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            if(map[y][x]->isInList(path))
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 12);
            }
            else
            {
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 15);
            }
            printf("%d ", map[y][x]->value);
        }
        printf("\n");
    }

  
}

