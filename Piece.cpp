//Christina Tsui
#include "Piece.h"

using namespace std;
using namespace Gaming;

unsigned int Piece::__idGen = 1;

Piece::Piece(const Game &g, const Position &p):__game(g)
{
    __id = __idGen;
    __idGen++;
    __finished = false;
    __turned = false;
    __position = p;
}

Piece::~Piece()
{

}

ostream & Gaming::operator<<(ostream &os, const Piece &piece)
{
    if(&piece != nullptr)
    {
        piece.print(os);
    }

    else
    {
        os << "";
    }
    return os;
}

