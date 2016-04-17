//Christina Tsui

#include "Simple.h"
#include <sstream>

using namespace std;
using namespace Gaming;

const char Simple::SIMPLE_ID = 'S';

Simple::Simple(const Game &g, const Position &p, double energy):Agent(g, p, energy)
{

}

Simple::~Simple()
{

}

void Simple::print(std::ostream &os) const
{
    stringstream ss;
    ss << SIMPLE_ID << __id;
    string s;
    getline(ss,s);
    os << s;
}

ActionType Simple::takeTurn(const Surroundings &s) const
{

    vector <ActionType> action = {NW,N,NE,W,STAY,E,SW,S,SE};
    vector <int> pieceIndex;
    int numDir = 0;

    random_device rd;
    mt19937 gen(rd());



    for (int i = 0; i < s.array.size(); ++i)
    {
        if(s.array[i] == FOOD || s.array[i] == ADVANTAGE)
        {
            pieceIndex.push_back(i);
            numDir++;
        }
    }

    if(numDir > 0)
    {
        uniform_int_distribution<> dis(0, numDir - 1);
        return action[pieceIndex[dis(gen)]];
    }

    for (int i = 0; i < s.array.size(); ++i)
    {
        if(s.array[i]==EMPTY)
        {
            pieceIndex.push_back(i);
            numDir++;
        }
    }

    if(numDir > 0)
    {
        uniform_int_distribution<> dis(0, numDir - 1);
        return action[pieceIndex[dis(gen)]];
    }
    return STAY;

}