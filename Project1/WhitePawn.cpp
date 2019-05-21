#include "stdafx.h"


bool WhitePawn::checkmove(int a, int b)
{
	nxtx = a;
	nxty = b;

	if (Piece::getPosition(nxtx, nxty).at(0) == ' ') {
		if (nxtx == curx) {
			if ((nxty - cury) == -1) {
				return true;
			}

			if ((nxty - cury) == -2)
			{
				if (cury == 7)
				{

					if (Piece::getPosition(curx, 6).at(0) == ' ') {
							return true;
					}
					

				}
				
			}
			
		}
		
	}

	else if (getPosition(nxtx, nxty).at(0) == 'b') {
		return ((abs(nxtx - curx) == 1) && ((cury - nxty) == 1));
	}

	return false;

}




