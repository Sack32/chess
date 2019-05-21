#pragma once
#include "Piece.h"



class BlackPawn :public Piece
{
public:
	bool checkmove(int,int);
	bool checkPromo(); //todo
	BlackPawn(int x, int y) :Piece(x, y) {};
};



