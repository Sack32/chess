#include "stdafx.h"





bool King::checkmove(int a, int b)
{	
	nxtx = a;
	nxty = b;
	if ((abs(nxtx - curx) <= 1) && (1 >= abs(cury - nxty))) {
		canCastle = false;

		return true;
	}
	if ((canCastle) && (((nxtx == 7) && (nxty == cury)) || ((nxtx == 3) && (nxty == cury)))) {
		int stepsx = abs(nxtx - curx);
		int dx = (nxtx - curx) / stepsx;
		for (int j = 1; j < stepsx; j++) {
			if (getPosition(curx + j * dx, cury).at(0) != ' ')
			{
				return false;
			}
		}
		canCastle = false;
		return true;
	}

	else {
		return false;
	}
}

