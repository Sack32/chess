#pragma once
#include "Piece.h"
class Rook :public Piece
{
public:
	bool checkmove(int,int);
	Rook(int x, int y) :Piece(x, y) {};
};

