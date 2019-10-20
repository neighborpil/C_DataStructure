#include <stdio.h>
#include "DBLinkedList.h"

int main(void)
{
	// 양방향 연결 리스트의 생성 및 초기화
	List list;
	Data data;
	ListInit(&list);

	// 8개의 데이터 저장
	for (int i = 1; i <= 8; i++) 
	{
		LInsert(&list, i);
	}

	// 저장된 데이터 조회
	if (LFirst(&list, &data))
	{
		printf("%d, ", data);

		while (LNext(&list, &data))
		{
			printf("%d, ", data);
		}

		while(LPrevious(&list, &data))
			printf("%d, ", data);

	}

	printf("\n\n");

	system("pause");

	return 0;
}