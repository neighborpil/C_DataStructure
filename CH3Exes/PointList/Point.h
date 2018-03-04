#ifndef __POINT_H__
#define __POINT_H__

typedef struct _point
{
	int xPos;
	int yPos;
} Point;


// Point ������ xPos, yPos �� ����
void SetPointPos(Point *ppos, int xPos, int yPos);

// Point ������ xPos, yPos ���� ���
void ShowPointPos(Point* ppos);

// �� Point ������ ��
int PointComp(Point* pos1, Point* pos2);

#endif // ! __POINT_H__
