#pragma once
#include <math.h>
#include <vector>

class CAStarNode
{
public:
    int x,y;
    float g = 0,h = 0,f = 0;
    int value;
    CAStarNode* parent = nullptr;

    bool IsOpen = false;//muito mais rapido do que isInList
    bool IsClosed = false;

    CAStarNode() {}
    CAStarNode(int x, int y,int value)
    {
        this->x = x;
        this->y = y;
        this->value = value;
    }

    bool isInList(std::vector<CAStarNode*> list);
    void calculateCost(int startX, int startY,int endX, int endY);
    int distanceTo(int x, int y);
private:

};
