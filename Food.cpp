//Christina Tsui
#include "Food.h"
#include <sstream>

using namespace std;
using namespace Gaming;

const char Food::FOOD_ID = 'F';
Food::Food(const Game &g, const Position &p, double capacity):Resource(g,p,capacity)
{

}

Food::~Food()
{

}

void Food::print(std::ostream &os) const
{
    stringstream ss;
    ss << FOOD_ID << __id;
    string s;
    getline(ss,s);
    os << s;
}