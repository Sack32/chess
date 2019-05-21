#pragma once
#include "Piece.h"
class Queen :public Piece
{
public:
	bool checkmove(int, int);
	Queen(int x, int y) :Piece(x, y) {};
};

