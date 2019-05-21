#include "stdafx.h"



bool BlackPawn::checkmove(int a, int b)
{
	nxtx = a;
	nxty = b;
	if (Piece::getPosition(nxtx, nxty).at(0) == ' ') {
		if (nxtx == curx) {
			if ((nxty - cury) == 1) {
				return true;
			}

			if (((nxty - cury) == 2) && (cury == 2))
			{
				if (Piece::getPosition(curx,3).at(0)==' ') {
					return true;
				}
			}
			
		}
	}



	else if (getPosition(nxtx, nxty).at(0) == 'w') {
		return ((abs(curx - nxtx) == 1) && ((nxty - cury) == 1));
	}
	return false;
	
}

bool BlackPawn::checkPromo()
{
	return (cury == 1);
}


