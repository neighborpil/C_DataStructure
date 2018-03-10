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
	SetSortRule(&list, WhoIsPrecede); // 정렬 기준 등록


	// 4개의 데이터 저장
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

	// 저장된 데이터의 출력
	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	puts("");

	// xPos가 2인 모든 데이터 삭제
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

	// 삭제 후 남은 데이터 표시
	printf("현재 데이터의 수 : %d \n", LCount(&list));

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