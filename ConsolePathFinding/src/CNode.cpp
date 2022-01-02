#include "CNode.h"

int CAStarNode::distanceTo(int x,int y)
{
    int dx = abs(x - this->x);
    int dy = abs(y - this->y);
    return dx+dy;
} 


void CAStarNode::calculateCost(int startX, int startY,int endX, int endY )
{   
    this->g = distanceTo(startX, startY);
    this->h = distanceTo(endX, endY);
    f = g + h;
}

bool CAStarNode::isInList(std::vector<CAStarNode*> list)
{
    for(int i = 0; i < list.size(); i++)
    {
        if(list[i]->x == x && list[i]->y == y)
            return true;
    }
    return false;
}