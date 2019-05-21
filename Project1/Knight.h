#pragma once
#include "Piece.h"
class Knight :public Piece
{
public:
	bool checkmove(int, int);
	Knight(int x, int y) :Piece(x, y) {};

};

