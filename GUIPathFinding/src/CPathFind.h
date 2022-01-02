#pragma once
#include <vector>
#include <utility>
#include <queue>
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
		void Init();
        void FreeMap();
        void PrintMap();
        void ResetMap();
	private:
        std::vector<CAStarNode*> GetNeighbors(CAStarNode* currentNode);
        std::vector<CAStarNode*> reconstructPath(CAStarNode* current);


        void PushOpen(CAStarNode* node);
        void PopOpen(CAStarNode* node);
    
        //std::priority_queue  for value f
        //less for value f
        //std::priority_queue<CAStarNode*, std::vector<CAStarNode*>, CompareNode> openList;


            
        std::vector<CAStarNode*> openList;
        std::vector<CAStarNode*> closedList;
};
