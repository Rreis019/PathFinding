#pragma once
#include <math.h>
#include <vector>
#include <stdio.h>
#include <functional>
class CAStarNode
{
public:
    int x = 0,y = 0;
    float g = 0,h = 0,f = 0;
    int value = 0;
    CAStarNode* parent = nullptr;

    bool IsOpen = false;//muito mais rapido do que isInList
    bool IsClosed = false;
    bool IsPath = false;

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

struct CompareNode
{
     bool operator()(const CAStarNode* lhs, const CAStarNode* rhs) const
    {
        return lhs->f > rhs->f;
    }
};