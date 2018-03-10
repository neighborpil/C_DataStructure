#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int WhoIsPrecede(LData d1, LData d2)
{
	if (d1->xPos < d2->yPos)
		return 0;
	else if (d1->xPos == d2->yPos)
	{
		if (d1->yPos < d2->yPos)
			return 0;
		else
			return 1;
	}
	else
		return 1;
}

int main(void)
{
	List list;
	Point compPos;
	Point* ppos;

	ListInit(&list);
	SetSortRule(&list, WhoIsPrecede); // ���� ���� ���


	// 4���� ������ ����
	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	// ����� �������� ���
	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	puts("");

	// xPos�� 2�� ��� ������ ����
	compPos.xPos = 2;
	compPos.yPos = 0;

	if (LFirst(&list, &ppos))
	{
		if (PointComp(ppos, &compPos) == 1)
		{
			ppos = LRemove(&list);
			free(ppos);
		}

		while (LNext(&list, &ppos))
		{
			if (PointComp(ppos, &compPos) == 1)
			{
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}

	// ���� �� ���� ������ ǥ��
	printf("���� �������� �� : %d \n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
		{
			ShowPointPos(ppos);
		}
	}

	system("pause");
	return 0;
}