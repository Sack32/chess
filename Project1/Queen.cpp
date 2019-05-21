#include "stdafx.h"



bool Queen::checkmove(int a,int b )
{
	nxtx = a;
	nxty = b;
	
	if (abs(nxtx - curx) == abs(nxty - cury)) {
		int steps = abs(curx - nxtx);
		int dx = (nxtx - curx) / steps;
		int dy = (nxty - cury) / steps;
		for (int i = 1; i < steps; i++) {
			if (getPosition(curx + i * dx, cury + i * dy).at(0) != ' ')
			{
				return false;
			}
		}
		return true;

	}
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
			if (getPosition(curx + j * dx, cury).at(0) != ' ')
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



