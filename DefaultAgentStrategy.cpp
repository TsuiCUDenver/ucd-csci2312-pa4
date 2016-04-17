//Christina Tsui
#include "DefaultAgentStrategy.h"

using namespace std;
using namespace Gaming;

DefaultAgentStrategy::DefaultAgentStrategy()
{

}

DefaultAgentStrategy::~DefaultAgentStrategy()
{

}

ActionType DefaultAgentStrategy::operator()(const Surroundings &s) const
{
    vector <ActionType> action = {NW,N,NE,W,STAY,E,SW,S,SE};
    vector <int> pieceIndex;

    for (int i = 0; i < s.array.size(); ++i)
    {
        if(s.array[i] == ADVANTAGE)
        {
            pieceIndex.push_back(i);
        }
    }

    if(pieceIndex.size() > 0)
    {
        PositionRandomizer p;
        Position ps = p(pieceIndex);
        return action[(ps.x * 3 + ps.y)];
    }

    for (int i = 0; i < s.array.size(); ++i)
    {
        if(s.array[i]==FOOD)
        {
            pieceIndex.push_back(i);
        }
    }

    if(pieceIndex.size() > 0)
    {
        PositionRandomizer p;
        Position ps = p(pieceIndex);
        return action[(ps.x * 3 + ps.y)];
    }

    for (int i = 0; i < s.array.size(); ++i)
    {
        if(s.array[i] == EMPTY)
        {
            pieceIndex.push_back(i);
        }
    }

    if(pieceIndex.size() > 0)
    {
        PositionRandomizer p;
        Position ps = p(pieceIndex);
        return action[(ps.x * 3 + ps.y)];
    }

    for (int i = 0; i < s.array.size(); ++i)
    {
        if(s.array[i] == SIMPLE)
        {
            pieceIndex.push_back(i);
        }
    }

    if(pieceIndex.size() > 0)
    {
        PositionRandomizer p;
        Position ps = p(pieceIndex);
        return action[(ps.x * 3 + ps.y)];
    }
    return STAY;
}
