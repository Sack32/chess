#include "stdafx.h"

bool wturn = true; //whites turn
bool turnAnnounced = false; //
int checkx, checky;
bool isitCheck= false;
bool checkmate = false;


//global shapes
sf::RectangleShape wbish1(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape wbish2(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape wrook1(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape wrook2(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape wknig1(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape wknig2(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape wking(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape wquee(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape wpawn1(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape wpawn2(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape wpawn3(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape wpawn4(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape wpawn5(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape wpawn6(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape wpawn7(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape wpawn8(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape bbish1(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape bbish2(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape brook1(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape brook2(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape bknig1(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape bknig2(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape bking(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape bquee(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape bpawn1(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape bpawn2(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape bpawn3(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape bpawn4(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape bpawn5(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape bpawn6(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape bpawn7(sf::Vector2f(60.0f, 60.0f));
sf::RectangleShape bpawn8(sf::Vector2f(60.0f, 60.0f));
//global sound?
sf::SoundBuffer buffer;	
sf::Sound sound;

//more global shape and window
sf::RectangleShape selector(sf::Vector2f(60.0f, 60.0f));//box to highlight which box has been selected
sf::RectangleShape checkerw(sf::Vector2f(60.0f, 60.0f));//box to highlight which box is checking white king
sf::RenderWindow window(sf::VideoMode(600, 600), "Chess", sf::Style::Close);//window

//global objects


Rook whiterook1(1, 8), whiterook2(8, 8), blackrook1(1, 1), blackrook2(8, 1);
Bishop whitebishop1(3, 8), whitebishop2(6, 8), blackbishop1(3, 1), blackbishop2(6, 1);
Knight whiteknight1(2, 8), whiteknight2(7, 8), blackknight1(2, 1), blackknight2(7, 1);
King whiteking(5, 8), blackking(5, 1);
Queen  whitequeen(4, 8), blackqueen(4, 1);
WhitePawn whitepawn1(1, 7), whitepawn2(2, 7), whitepawn3(3, 7), whitepawn4(4, 7), whitepawn5(5, 7), whitepawn6(6, 7), whitepawn7(7, 7), whitepawn8(8, 7);
BlackPawn blackpawn1(1, 2), blackpawn2(2, 2), blackpawn3(3, 2), blackpawn4(4, 2), blackpawn5(5, 2), blackpawn6(6, 2), blackpawn7(7, 2), blackpawn8(8, 2);


void move(int, int, int, int);//func to move pieces in array

bool checkmovevalidity(int, int, int, int);//to check if it can move
void moveclass(int, int, int, int); //move piece in class
bool check_check();
void check(int, int);

//enumerating for hash function
enum string_code : unsigned char
{ 
	zero,
	ewr1,
	ewk1,
	ewb1,
	ewq,
	ewk,
	ewb2,
	ewk2,
	ewr2,
	ewp1,
	ewp2,
	ewp3,
	ewp4,
	ewp5,
	ewp6,
	ewp7,
	ewp8,
	ebp1,
	ebp2,
	ebp3,
	ebp4,
	ebp5,
	ebp6,
	ebp7,
	ebp8,
	ebr1,
	ebk1,
	ebb1,
	ebq,
	ebk,
	ebb2,
	ebk2,
	ebr2,
}; 

//hash function for switch case of string
string_code hashit(std::string const& inString) {
	if (inString == "wr1") return ewr1;
	if (inString == "wk1") return ewk1;
	if (inString == "wb1") return ewb1;
	if (inString == "wq") return ewq;
	if (inString == "wk") return ewk;
	if (inString == "wb2") return ewb2;
	if (inString == "wk2") return ewk2;
	if (inString == "wr2") return ewr2;
	if (inString == "wp1") return ewp1;
	if (inString == "wp2") return ewp2;
	if (inString == "wp3") return ewp3;
	if (inString == "wp4") return ewp4;
	if (inString == "wp5") return ewp5;
	if (inString == "wp6") return ewp6;
	if (inString == "wp7") return ewp7;
	if (inString == "wp8") return ewp8;
	if (inString == "bp1") return ebp1;
	if (inString == "bp2") return ebp2;
	if (inString == "bp3") return ebp3;
	if (inString == "bp4") return ebp4;
	if (inString == "bp5") return ebp5;
	if (inString == "bp6") return ebp6;
	if (inString == "bp7") return ebp7;
	if (inString == "bp8") return ebp8;
	if (inString == "br1") return ebr1;
	if (inString == "bk1") return ebk1;
	if (inString == "bb1") return ebb1;
	if (inString == "bq") return ebq;
	if (inString == "bk") return ebk;
	if (inString == "bb2") return ebb2;
	if (inString == "bk2") return ebk2;
	if (inString == "br2") return ebr2;
	return zero;
}



//func to draw piecces
void drawPieces()
{
	for (int posx = 1; posx <= 8; posx++) {


		for (int posy = 1; posy <= 8; posy++) {


			switch (hashit(Piece::position[posx][posy])) {

			case ewr1:
				wrook1.setPosition(static_cast<float>((60 * posx) - 28), static_cast<float>((60 * posy) - 28));//set position of rectangle
				window.draw(wrook1);
				break;

			case ewr2:
				wrook2.setPosition(static_cast<float>((60 * posx) - 28), static_cast<float>((60 * posy) - 28));
				window.draw(wrook2);
				break;
			case ewk1:
				wknig1.setPosition(static_cast<float>((60 * posx) - 28), static_cast<float>((60 * posy) - 28));
				window.draw(wknig1);
				break;

			case ewk2:
				wknig2.setPosition(static_cast<float>((60 * posx) - 28), static_cast<float>((60 * posy) - 28));
				window.draw(wknig2);
				break;


			case ewb1:
				wbish1.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(wbish1);
				break;

			case ewb2:
				wbish2.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(wbish2);
				break;

			case ewk:
				wking.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(wking);
				break;

			case ewq:
				wquee.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(wquee);
				break;

			case ewp1:
				wpawn1.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(wpawn1);
				break;

			case ewp2:
				wpawn2.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(wpawn2);
				break;

			case ewp3:
				wpawn3.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(wpawn3);
				break;

			case ewp4:
				wpawn4.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(wpawn4);
				break;

			case ewp5:
				wpawn5.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(wpawn5);
				break;

			case ewp6:
				wpawn6.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(wpawn6);
				break;

			case ewp7:
				wpawn7.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(wpawn7);
				break;

			case ewp8:
				wpawn8.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(wpawn8);
				break;


			case ebr1:
				brook1.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(brook1);
				break;

			case ebr2:
				brook2.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(brook2);
				break;

			case ebk1:
				bknig1.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(bknig1);
				break;

			case ebk2:
				bknig2.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(bknig2);
				break;


			case ebb1:
				bbish1.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(bbish1);
				break;

			case ebb2:
				bbish2.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(bbish2);
				break;

			case ebk:
				bking.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(bking);
				break;

			case ebq:
				bquee.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(bquee);
				break;

			case ebp1:
				bpawn1.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(bpawn1);
				break;

			case ebp2:
				bpawn2.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(bpawn2);
				break;

			case ebp3:
				bpawn3.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(bpawn3);
				break;

			case ebp4:
				bpawn4.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(bpawn4);
				break;

			case ebp5:
				bpawn5.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(bpawn5);
				break;

			case ebp6:
				bpawn6.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(bpawn6);
				break;

			case ebp7:
				bpawn7.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(bpawn7);
				break;

			case ebp8:
				bpawn8.setPosition((float)((60 * posx) - 28), ((float)((60 * posy) - 28)));
				window.draw(bpawn8);
				break;






			}


		}
	}
}

//func to convert box y coordinate to name  
int sqnmy(const int px)
{
	return 9 - px;

}

//func to convert box x coordinate to name
char sqnmx(int py)
{
	switch (py) {
	case 1:
		return 'A';

	case 2:
		return 'B';

	case 3:
		return 'C';

	case 4:
		return 'D';

	case 5:
		return 'E';

	case 6:
		return 'F';

	case 7:
		return 'G';

	case 8:
		return 'H';

	default:
		return '0';
	}

}




//function after select box is selected and check if it can be moved to second box
void select(int row, int column)
{

	

		//drawing selector
		selector.setPosition(static_cast<float>((row - 1) * 60), static_cast<float>((column - 1) * 60));
		window.draw(selector);
		


		drawPieces();
		window.display();
	
		
		printf("%c%d  \n", sqnmx(row), sqnmy(column));//print algebraic name
		

		

		
	bool movedone = false;//boolean value of whether move completed
	do
	{
		
	
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))//select second position
		{
			sf::Vector2i mousep = sf::Mouse::getPosition(window);
			
				if ((2 < mousep.x) && (mousep.x < 482) && (2 < mousep.y) && (mousep.y < 482))//to check if selected place is box
				{
					
					int selx2 = (mousep.x - 2) / 60;
					int sely2 = (mousep.y - 2) / 60;
					selx2++;//inc as value in array start from 1,1
					sely2++;
					if (!((selx2==row)&&(sely2==column))) {  //check if same box selected
						if (Piece::getPosition(selx2,sely2).at(0) != Piece::getPosition(row,column).at(0)) {  //check if same coloured at box 2

							if ((checkmovevalidity(row, column, selx2, sely2))) {
								moveclass(row, column, selx2, sely2);
								move(row, column, selx2, sely2);							

							}
			
							
						}
						movedone = true;//move completed
						isitCheck = false;
				}
			}
		}
	} while (!movedone);



}


void move(int spos1, int spos2,int fpos1, int fpos2)//function after secon point is verified to move the piece in array
{
		//move in array
		Piece::setPosition(fpos1,fpos2,Piece::getPosition(spos1,spos2));
		Piece::setPosition(spos1,spos2," ");
		printf("%c%d  \n", sqnmx(fpos1), sqnmy(fpos2));
		


		drawPieces();


		//turn changed and sound played
		wturn = !wturn;
		sound.play();

	

	

}

//checking if move is legal
bool checkmovevalidity(int initx, int inity, int finalx, int finaly)
{

	std::cout << Piece::getPosition(initx, inity) << std::endl;




	switch (hashit(Piece::getPosition(initx, inity))) {



	case ewr1:
		return whiterook1.checkmove(finalx, finaly);
		break;

	case ewr2:
		return whiterook2.checkmove(finalx, finaly);
		break;

	case ewk1:
		return whiteknight1.checkmove(finalx, finaly);
		break;

	case ewk2:
		return whiteknight2.checkmove(finalx, finaly);
		break;


	case ewb1:
		return whitebishop1.checkmove(finalx, finaly);
		break;

	case ewb2:
		return whitebishop2.checkmove(finalx, finaly);
		break;

	case ewk:
		return whiteking.checkmove(finalx, finaly);
		break;

	case ewq:
		return whitequeen.checkmove(finalx, finaly);
		break;

	case ewp1:
		return whitepawn1.checkmove(finalx, finaly);
		break;

	case ewp2:
		return whitepawn2.checkmove(finalx, finaly);
		break;

	case ewp3:
		return whitepawn3.checkmove(finalx, finaly);
		break;

	case ewp4:
		return whitepawn4.checkmove(finalx, finaly);
		break;

	case ewp5:
		return whitepawn5.checkmove(finalx, finaly);
		break;

	case ewp6:
		return whitepawn6.checkmove(finalx, finaly);
		break;

	case ewp7:
		return whitepawn7.checkmove(finalx, finaly);
		break;

	case ewp8:
		return whitepawn8.checkmove(finalx, finaly);
		break;


	case ebr1:
		return blackrook1.checkmove(finalx, finaly);
		break;

	case ebr2:
		return blackrook2.checkmove(finalx, finaly);
		break;

	case ebk1:
		return blackknight1.checkmove(finalx, finaly);
		break;

	case ebk2:
		return blackknight2.checkmove(finalx, finaly);
		break;


	case ebb1:
		return blackbishop1.checkmove(finalx, finaly);
		break;

	case ebb2:
		return blackbishop2.checkmove(finalx, finaly);
		break;

	case ebk:
		return blackking.checkmove(finalx, finaly);
		break;

	case ebq:
		return blackqueen.checkmove(finalx, finaly);
		break;

	case ebp1:
		return blackpawn1.checkmove(finalx, finaly);
		break;

	case ebp2:
		return blackpawn2.checkmove(finalx, finaly);
		break;

	case ebp3:
		return blackpawn3.checkmove(finalx, finaly);
		break;

	case ebp4:
		return blackpawn4.checkmove(finalx, finaly);
		break;

	case ebp5:
		return blackpawn5.checkmove(finalx, finaly);
		break;

	case ebp6:
		return blackpawn6.checkmove(finalx, finaly);
		break;

	case ebp7:
		return blackpawn7.checkmove(finalx, finaly);
		break;

	case ebp8:
		return blackpawn8.checkmove(finalx, finaly);
		break;


	}
}


	
//move pieces in class
void moveclass(int initx,int inity,int finalx,int finaly){

		switch (hashit(Piece::getPosition(initx,inity))) {


		case ewr1:
			whiterook1.move(finalx, finaly);
			break;

		case ewr2:
			whiterook2.move(finalx, finaly);
			break;

		case ewk1:
			whiteknight1.move(finalx, finaly);
			break;

		case ewk2:
			whiteknight2.move(finalx, finaly);
			break;


		case ewb1:
			whitebishop1.move(finalx, finaly);
			break;

		case ewb2:
			whitebishop2.move(finalx, finaly);
			break;

		case ewk:
			if (2 == abs(whiteking.curx - finalx))
			{
				if (finalx == 7)
				{
					whiterook2.move(6, 8);
					Piece::setPosition(6, 8, Piece::getPosition(8, 8));
					Piece::setPosition(8, 8, " ");
				}
				if (finalx == 3)
				{					
					whiterook1.move(4, 8);
					Piece::setPosition(4, 8, Piece::getPosition(1, 8));
					Piece::setPosition(1, 8, " ");
				}
			}
			whiteking.move(finalx, finaly);
			break;

		case ewq:
			whitequeen.move(finalx, finaly);
			break;

		case ewp1:
			whitepawn1.move(finalx, finaly);
			break;

		case ewp2:
			whitepawn2.move(finalx, finaly);
			break;

		case ewp3:
			whitepawn3.move(finalx, finaly);
			break;

		case ewp4:
			whitepawn4.move(finalx, finaly);
			break;

		case ewp5:
			whitepawn5.move(finalx, finaly);
			break;

		case ewp6:
			whitepawn6.move(finalx, finaly);
			break;

		case ewp7:
			 whitepawn7.move(finalx, finaly);
			break;

		case ewp8:
			 whitepawn8.move(finalx, finaly);
			break;


		case ebr1:
			 blackrook1.move(finalx, finaly);
			break;

		case ebr2:
			 blackrook2.move(finalx, finaly);
			break;

		case ebk1:
			 blackknight1.move(finalx, finaly);
			break;

		case ebk2:
			 blackknight2.move(finalx, finaly);
			break;


		case ebb1:
			 blackbishop1.move(finalx, finaly);
			break;

		case ebb2:
			 blackbishop2.move(finalx, finaly);
			break;

		case ebk:
			if (2 == abs(blackking.curx - finalx))
			{
				if (finalx == 7)
				{
					blackrook2.move(6, 1);
					Piece::setPosition(6, 1, Piece::getPosition(8, 1));
					Piece::setPosition(8, 1, "  ");
				}
				if (finalx == 3)
				{
					blackrook1.move(4, 1);
					Piece::setPosition(4, 1, Piece::getPosition(1, 1));
					Piece::setPosition(1, 1, "  ");
				}
			}
			 blackking.move(finalx, finaly);
			break;

		case ebq:
			 blackqueen.move(finalx, finaly);
			break;

		case ebp1:
			 blackpawn1.move(finalx, finaly);
			break;

		case ebp2:
			 blackpawn2.move(finalx, finaly);
			break;

		case ebp3:
			 blackpawn3.move(finalx, finaly);
			break;

		case ebp4:
			 blackpawn4.move(finalx, finaly);
			break;

		case ebp5:
			 blackpawn5.move(finalx, finaly);
			break;

		case ebp6:
			 blackpawn6.move(finalx, finaly);
			break;

		case ebp7:
			 blackpawn7.move(finalx, finaly);
			break;

		case ebp8:
			 blackpawn8.move(finalx, finaly);
			break;


		}
	}


bool check_check()
	{
		for (int l = 1; l < 8; l++) {
			for (int m = 1; m < 8; m++) {
				if (wturn)
				{
					if (Piece::getPosition(l, m).at(0) == 'b')
					{
						switch (hashit(Piece::getPosition(l, m)))
						{
						case ebr1:
							if (blackrook1.checkmove(whiteking.curx, whiteking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ebr2:
							if (blackrook2.checkmove(whiteking.curx, whiteking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ebk1:
							if (blackknight1.checkmove(whiteking.curx, whiteking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ebk2:
							if (blackknight2.checkmove(whiteking.curx, whiteking.cury))
							{
								check(l, m);
								return true;
							}
							break;


						case ebb1:
							if (blackbishop1.checkmove(whiteking.curx, whiteking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ebb2:
							if (blackbishop2.checkmove(whiteking.curx, whiteking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ebk:
							if (blackking.checkmove(whiteking.curx, whiteking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ebq:
							if (blackqueen.checkmove(whiteking.curx, whiteking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ebp1:
							if (blackpawn1.checkmove(whiteking.curx, whiteking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ebp2:
							if (blackpawn2.checkmove(whiteking.curx, whiteking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ebp3:
							if (blackpawn3.checkmove(whiteking.curx, whiteking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ebp4:
							if (blackpawn4.checkmove(whiteking.curx, whiteking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ebp5:
							if (blackpawn5.checkmove(whiteking.curx, whiteking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ebp6:
							if (blackpawn6.checkmove(whiteking.curx, whiteking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ebp7:
							if (blackpawn7.checkmove(whiteking.curx, whiteking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ebp8:
							if (blackpawn8.checkmove(whiteking.curx, whiteking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						}
					}
				}
				else {
					if (Piece::getPosition(l, m).at(0) == 'w')
					{
						switch (hashit(Piece::getPosition(l, m)))
						{
						case ewr1:
							if (whiterook1.checkmove(blackking.curx, blackking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ewr2:
							if (whiterook2.checkmove(blackking.curx, blackking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ewk1:
							if (whiteknight1.checkmove(blackking.curx, blackking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ewk2:
							if (whiteknight2.checkmove(blackking.curx, blackking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ewb1:
							if (whitebishop1.checkmove(blackking.curx, blackking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ewb2:
							if (whitebishop2.checkmove(blackking.curx, blackking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ewk:
							if (whiteking.checkmove(blackking.curx, blackking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ewq:
							if (whitequeen.checkmove(blackking.curx, blackking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ewp1:
							if (whitepawn1.checkmove(blackking.curx, blackking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ewp2:
							if (whitepawn2.checkmove(blackking.curx, blackking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ewp3:
							if (whitepawn3.checkmove(blackking.curx, blackking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ewp4:
							if (whitepawn4.checkmove(blackking.curx, blackking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ewp5:
							if (whitepawn5.checkmove(blackking.curx, blackking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ewp6:
							if (whitepawn6.checkmove(blackking.curx, blackking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ewp7:
							if (whitepawn7.checkmove(blackking.curx, blackking.cury))
							{
								check(l, m);
								return true;
							}
							break;

						case ewp8:
							if (whitepawn8.checkmove(blackking.curx, blackking.cury))
							{
								check(l, m);
								return true;
							}
							break;
						}
					}
				}

			}
		}
		return false;
	}

	void check(int x,int y) {
		checkerw.setPosition(static_cast<float>(60 * (x - 1)), static_cast<float>(60 * (y - 1)));

		isitCheck = true;
		drawPieces();

	}

	std::string Piece::position[][9]={" "};


int main()
{
	Piece::assignArray();





	









	sf::RectangleShape blacksquare(sf::Vector2f(60.0f, 60.0f));
	sf::RectangleShape whitesquare(sf::Vector2f(60.0f, 60.0f));
	sf::RectangleShape edge(sf::Vector2f(484.0f, 484.0f));

	sf::Music music;
	music.openFromFile("Doki.wav");

	music.setVolume(20.f);
	music.play();


	buffer.loadFromFile("17892__zippi1__sound-click2.wav");

	sound.setBuffer(buffer);
	sound.setVolume(50.f);




	wbish1.setOrigin(30.0f, 30.0f);
	wbish2.setOrigin(30.0f, 30.0f);
	wrook1.setOrigin(30.0f, 30.0f);
	wrook2.setOrigin(30.0f, 30.0f);
	wknig1.setOrigin(30.0f, 30.0f);
	wknig2.setOrigin(30.0f, 30.0f);
	wking.setOrigin(30.0f, 30.0f);
	wquee.setOrigin(30.0f, 30.0f);
	wpawn1.setOrigin(30.0f, 30.0f);
	wpawn2.setOrigin(30.0f, 30.0f);
	wpawn3.setOrigin(30.0f, 30.0f);
	wpawn4.setOrigin(30.0f, 30.0f);
	wpawn5.setOrigin(30.0f, 30.0f);
	wpawn6.setOrigin(30.0f, 30.0f);
	wpawn7.setOrigin(30.0f, 30.0f);
	wpawn8.setOrigin(30.0f, 30.0f);
	bbish1.setOrigin(30.0f, 30.0f);
	bbish2.setOrigin(30.0f, 30.0f);
	brook1.setOrigin(30.0f, 30.0f);
	brook2.setOrigin(30.0f, 30.0f);
	bknig1.setOrigin(30.0f, 30.0f);
	bknig2.setOrigin(30.0f, 30.0f);
	bking.setOrigin(30.0f, 30.0f);
	bquee.setOrigin(30.0f, 30.0f);
	bpawn1.setOrigin(30.0f, 30.0f);
	bpawn2.setOrigin(30.0f, 30.0f);
	bpawn3.setOrigin(30.0f, 30.0f);
	bpawn4.setOrigin(30.0f, 30.0f);
	bpawn5.setOrigin(30.0f, 30.0f);
	bpawn6.setOrigin(30.0f, 30.0f);
	bpawn7.setOrigin(30.0f, 30.0f);
	bpawn8.setOrigin(30.0f, 30.0f);

	whitesquare.setOrigin(30.0f, 30.0f);
	blacksquare.setOrigin(30.0f, 30.0f);
	whitesquare.setFillColor(sf::Color(255, 255, 255));
	blacksquare.setFillColor(sf::Color(10, 50, 110));
	edge.setFillColor(sf::Color(72, 5, 22));

	selector.setOrigin(-2.0f, -2.0f);
	selector.setFillColor(sf::Color(255, 255, 0));
	checkerw.setOrigin(-2.0f, -2.0f);
	checkerw.setFillColor(sf::Color(255, 0, 0));
	checkerw.setPosition(-100, -100);


	sf::Texture wbishtexture;
	wbishtexture.loadFromFile("Chess_blt60.png");
	wbish1.setTexture(&wbishtexture);
	wbish2.setTexture(&wbishtexture);

	sf::Texture wrooktexture;
	wrooktexture.loadFromFile("Chess_rlt60.png");
	wrook1.setTexture(&wrooktexture);
	wrook2.setTexture(&wrooktexture);

	sf::Texture wknigtexture;
	wknigtexture.loadFromFile("Chess_nlt60.png");
	wknig1.setTexture(&wknigtexture);
	wknig2.setTexture(&wknigtexture);

	sf::Texture wkingtexture;
	wkingtexture.loadFromFile("Chess_klt60.png");
	wking.setTexture(&wkingtexture);

	sf::Texture wqueetexture;
	wqueetexture.loadFromFile("Chess_qlt60.png");
	wquee.setTexture(&wqueetexture);

	sf::Texture wpawntexture;
	wpawntexture.loadFromFile("Chess_plt60.png");
	wpawn1.setTexture(&wpawntexture);
	wpawn2.setTexture(&wpawntexture);
	wpawn3.setTexture(&wpawntexture);
	wpawn4.setTexture(&wpawntexture);
	wpawn5.setTexture(&wpawntexture);
	wpawn6.setTexture(&wpawntexture);
	wpawn7.setTexture(&wpawntexture);
	wpawn8.setTexture(&wpawntexture);

	sf::Texture bbishtexture;
	bbishtexture.loadFromFile("Chess_bdt60.png");
	bbish1.setTexture(&bbishtexture);
	bbish2.setTexture(&bbishtexture);

	sf::Texture brooktexture;
	brooktexture.loadFromFile("Chess_rdt60.png");
	brook1.setTexture(&brooktexture);
	brook2.setTexture(&brooktexture);

	sf::Texture bknigtexture;
	bknigtexture.loadFromFile("Chess_ndt60.png");
	bknig1.setTexture(&bknigtexture);
	bknig2.setTexture(&bknigtexture);

	sf::Texture bkingtexture;
	bkingtexture.loadFromFile("Chess_kdt60.png");
	bking.setTexture(&bkingtexture);

	sf::Texture bqueetexture;
	bqueetexture.loadFromFile("Chess_qdt60.png");
	bquee.setTexture(&bqueetexture);

	sf::Texture bpawntexture;
	bpawntexture.loadFromFile("Chess_pdt60.png");
	bpawn1.setTexture(&bpawntexture);
	bpawn2.setTexture(&bpawntexture);
	bpawn3.setTexture(&bpawntexture);
	bpawn4.setTexture(&bpawntexture);
	bpawn5.setTexture(&bpawntexture);
	bpawn6.setTexture(&bpawntexture);
	bpawn7.setTexture(&bpawntexture);
	bpawn8.setTexture(&bpawntexture);
	


	while (window.isOpen())
	{
		sf::Event vent{};



		while (window.pollEvent(vent))
		{
			switch (vent.type)
			{
			case sf::Event::Closed:
				window.close();
				break;




			}

		}





		window.draw(edge);
		bool whitecheck = false;
		for (int i = 0; i < 8; i++) {
			whitecheck = !whitecheck;
			for (int j = 0; j < 8; j++)
			{
				whitesquare.setPosition(static_cast<float>((60 * i) + 32), static_cast<float>((60 * j) + 32));
				blacksquare.setPosition(static_cast<float>((60 * i) + 32), static_cast<float>((60 * j) + 32));
				if (whitecheck)
					window.draw(whitesquare);
				else
					window.draw(blacksquare);


				whitecheck = !whitecheck;

			}

		}

		if(isitCheck)
		{
			window.draw(checkerw);
		}

		drawPieces();

		if (!turnAnnounced) {
			if (wturn) {
				std::cout << "white turn ";
			}
			else {
				std::cout << "black turn ";
			}
			turnAnnounced = true;
		}



		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))

		{
			sf::Vector2i mousep = sf::Mouse::getPosition(window);
			if ((2 < mousep.x) && (mousep.x < 482) && (2 < mousep.y) && (mousep.y < 482))
			{
				int selx = (mousep.x - 2) / 60;
				int sely = (mousep.y - 2) / 60;
				selx++;
				sely++;

				if (((Piece::getPosition(selx, sely).at(0) == 'w') && (wturn)) || ((Piece::getPosition(selx, sely).at(0) == 'b') && (!wturn)))

					select(selx, sely);



			}

		}

		check_check();

		if (checkmate)
			window.close();


		window.display();


	}

	//gameover();

	return 0;
}
