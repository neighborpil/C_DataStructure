#include <stdio.h>
#include "Point.h"

void SetPointPos(Point* ppos, int xPos, int yPos)
{
	ppos->xPos = xPos;
	ppos->yPos = yPos;
}

void ShowPointPos(Point* ppos)
{
	printf("[%d %d] \n", ppos->xPos, ppos->yPos);
}

int PointComp(Point* pos1, Point* pos2)
{
	if (pos1->xPos == pos2->xPos && pos1->yPos == pos2->yPos)
		return 0;
	if (pos1->xPos == pos2->xPos)
		return 1;
	if (pos1->yPos == pos2->yPos)
		return 2;
	else
		return -1;
}