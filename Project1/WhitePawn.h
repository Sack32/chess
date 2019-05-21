#pragma once
#include "Piece.h"


class WhitePawn :public Piece
{
public:
	bool checkmove(int, int);
	WhitePawn(int x, int y) :Piece(x, y) {};
};



