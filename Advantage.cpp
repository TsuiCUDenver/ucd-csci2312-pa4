//Christina Tsui
#include "Advantage.h"
#include <sstream>

using namespace std;
using namespace Gaming;

const char Advantage::ADVANTAGE_ID = 'D';
const double Advantage::ADVANTAGE_MULT_FACTOR = 2.0;

Advantage::Advantage(const Game &g, const Position &p, double capacity):Resource(g,p,capacity)
{

}

Advantage::~Advantage()
{

}

void Advantage::print(ostream &os) const
{
    stringstream ss;
    ss << ADVANTAGE_ID << __id;
    string s;
    getline(ss,s);
    os << s;
}

double Advantage::getCapacity() const
{
    return (__capacity*ADVANTAGE_MULT_FACTOR);
}

double Advantage::consume()
{
    double temp = getCapacity();
    __capacity = 0;
    finish();
    return temp;
}
