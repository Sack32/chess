#include "stdafx.h"






Piece::Piece(int x, int y)
{
	curx = x;
	cury = y;

}


Piece::~Piece()
= default;


void Piece::move(int a, int b) {

	curx = a;
	cury = b;


}


void Piece::assignArray()
{
	position[1][8] = "wr1";
	position[2][8] = "wk1";
	position[3][8] = "wb1";
	position[4][8] = "wq";
	position[5][8] = "wk";
	position[6][8] = "wb2";
	position[7][8] = "wk2";
	position[8][8] = "wr2";
	position[1][7] = "wp1";
	position[2][7] = "wp2";
	position[3][7] = "wp3";
	position[4][7] = "wp4";
	position[5][7] = "wp5";
	position[6][7] = "wp6";
	position[7][7] = "wp7";
	position[8][7] = "wp8";
	position[1][2] = "bp1";
	position[2][2] = "bp2";
	position[3][2] = "bp3";
	position[4][2] = "bp4";
	position[5][2] = "bp5";
	position[6][2] = "bp6";
	position[7][2] = "bp7";
	position[8][2] = "bp8";
	position[1][1] = "br1";
	position[2][1] = "bk1";
	position[3][1] = "bb1";
	position[4][1] = "bq";
	position[5][1] = "bk";
	position[6][1] = "bb2";
	position[7][1] = "bk2";
	position[8][1] = "br2";

	for (int count2 = 3; count2 < 7; count2++) {
		for (int count1 = 1; count1 <= 8; count1++) {
			position[count1][count2] = "  ";
		}
	}
	
}

void Piece::getName()
{
	
	name = position[curx][cury];
	std::cout <<'/b'<< name;
	
}

std::string Piece::getPosition(int a, int b)
{
	return position[a][b];
}

void Piece::setPosition(int a, int b,std::string c)
{
	std::swap(position[a][b],c);
}


