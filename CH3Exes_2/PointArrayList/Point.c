#include <stdio.h>
#include "Point.h"

void SetPointPos(Point* ppos, int xpos, int ypos)
{
	ppos->xpos = xpos;
	ppos->ypos = ypos;
}

void ShowPointPos(Point* ppos)
{
	printf("X: %d, Y: %d \n", ppos->xpos, ppos->ypos);
}

int PointComp(Point* pos1, Point* pos2)
{
	if (pos1->xpos == pos2->ypos && pos1->ypos == pos2->ypos)
		return 0;
	else if (pos1->xpos == pos2->ypos)
		return 1;
	else if (pos1->ypos == pos2->ypos)
		return 2;

	return -1;
}

