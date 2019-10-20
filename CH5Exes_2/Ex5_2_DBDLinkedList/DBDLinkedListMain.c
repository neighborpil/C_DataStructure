#include <stdio.h>
#include "DBDLinkedList.h"

int main(void)
{
	// ����� ���� ����Ʈ�� ���� �� �ʱ�ȭ
	List list;
	Data data;
	ListInit(&list);

	// 8���� ������ ����
	for (int i = 1; i <= 8; i++) 
	{
		LInsert(&list, i);
	}

	// ����� ������ ��ȸ
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


	// 6 ����

	int removeData = 6;
	if (LFirst(&list, &data))
	{
		if (data == removeData)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == removeData)
				LRemove(&list);
		}
	}

	// �ٽ� ��ȸ
	if (LFirst(&list, &data))
	{
		printf("%d, ", data);

		while (LNext(&list, &data))
		{
			printf("%d, ", data);
		}

		while (LPrevious(&list, &data))
			printf("%d, ", data);

	}

	printf("\n\n");


	system("pause");

	return 0;
}