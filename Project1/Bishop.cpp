#include "stdafx.h"



bool Bishop::checkmove(int a,int b)
{	
	nxtx = a;
	nxty = b;
	if (abs(nxtx - curx)==abs(nxty-cury)) {
		int steps = abs(curx - nxtx);
		int dx = (nxtx - curx)/steps;
		int dy = (nxty - cury)/steps;
		for (int i = 1; i < steps;i++) {
				if (getPosition(curx+i*dx,cury+i*dy).at(0)!=' ')
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
