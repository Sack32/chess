#pragma once
#include "Piece.h"
class Bishop :	public Piece
{
public:
	bool checkmove(int, int);
	Bishop(int x, int y) :Piece(x, y) {};
};

