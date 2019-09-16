#include <stdio.h>
#include "ArrayList.h"

#define TRUE 1 
#define FALSE 0 

int main(void)
{
	// ArrayList 생성 및 초기화
	List list;
	int data;
	ListInit(&list);

	// 5개의 데이터 저장
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 33);
	LInsert(&list, 44);
	LInsert(&list, 55);

	// 전체 출력
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data)) // 첫번째 데이터 조회
	{
		printf("%d ", data);

		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}

	printf("\n\n");

	// 22탐색하여 모두 삭제
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

	// 삭제 후 남은 데이터 출력
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}

	printf("\n\n");

	List list2;
	int data2;
	ListInit(&list2);

	for (int i = 0; i < 10; i++)
	{
		LInsert(&list2, i);

	}

	int sum = 0;

	if (LFirst(&list2, &data2)) {
		sum += data2;

		while (TRUE)
		{
			if (!LNext(&list2, &data2))
				break;
			sum += data2;
		}
	}

	printf("sum: %d \n", sum);

	system("pause");

	return 0;
}