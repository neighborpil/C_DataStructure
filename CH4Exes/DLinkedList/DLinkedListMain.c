#include <stdio.h>
#include "DLinkedList.h"


int WhoIsPrecede(LData d1, LData d2)
{
	if (d1 < d2)
		return 0;
	else
		return 1;
}


int main(void)
{
	// ArrayList의 생성 및 초기화
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede); // 정렬 기준 등록

	// 5개의 데이터 저장
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);

	// 저장된 데이터의 전체 출력
	printf("현재 데이터의 수 : %d \n", LCount(&list));

	if (LFirst(&list, &data)) // 첫번째 데이터 조회
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// 숫자 22를 탐색하여 모두 삭제
	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	// 삭제 후 남은 데이터 전체 출력
	printf("현재 데이터 수 : %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	system("pause");
}
