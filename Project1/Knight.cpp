#include "stdafx.h"



bool Knight::checkmove(int a,int b)

{
	
	nxtx = a;
	nxty = b;
	return (((abs(nxtx - curx) == 1) && (abs(nxty - cury) == 2)) || ((abs(nxtx - curx) == 2) && (abs(nxty - cury) == 1)));
	
	
}

