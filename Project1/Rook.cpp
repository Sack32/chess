#include "stdafx.h"



bool Rook::checkmove(int a, int b)
{
	nxtx = a;
	nxty = b;
	if (nxtx == curx) {
		int stepsy = abs(nxty - cury);
		int dy = (nxty - cury) / stepsy;
		for (int i = 1; i < stepsy; i++) {
			if (getPosition(curx, cury + i * dy).at(0) != ' ')
			{
				return false;
			}
		}
		return true;
	}
	if (nxty == cury)
	{
		int stepsx = abs(nxtx - curx);
		int dx = (nxtx - curx) / stepsx;
		for (int j = 1; j < stepsx; j++) {
			if (getPosition(curx + j * dx, cury ).at(0) != ' ')
			{
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}


