#pragma once
#include <string>
class Piece
{
private:
protected:

	std::string name;

	int nxtx, nxty;

public:
	static std::string position[9][9]; //array of all positions 

	int curx, cury;


public:


	Piece(int, int);
	~Piece();

	void move(int,int);
	static void assignArray();
	void getName();
	static std::string getPosition(int, int);
	static void setPosition(int, int,std::string);


};

