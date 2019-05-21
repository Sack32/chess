#pragma once
#include "Piece.h"
class King :public Piece
{
public:
	bool checkmove(int, int);
	King(int x, int y) :Piece(x, y) {};
private:
	bool canCastle=true;
};

