#pragma once
#include <vector>
#include <utility>
#include "CNode.h"

typedef CAStarNode** Map;//Map[y][x]
  
class CPathFind
{
	public:
		Map* map;//0 = walkable, 1 = unwalkable
        int width = 0, height = 0;

        CPathFind(){}

        std::vector<CAStarNode*> FindPath(int startX, int startY, int endX, int endY);
        void VisualizePath(std::vector<CAStarNode*> path);
		void LoadMap(char* filename);
        void FreeMap();
        void PrintMap();
        void ResetMap();
	private:
        std::vector<CAStarNode*> GetNeighbors(CAStarNode* currentNode);
        std::vector<CAStarNode*> reconstructPath(CAStarNode* current);


        void PushOpen(CAStarNode* node);
        void PopOpen(CAStarNode* node);
        std::vector<CAStarNode*> openList, closedList;
};