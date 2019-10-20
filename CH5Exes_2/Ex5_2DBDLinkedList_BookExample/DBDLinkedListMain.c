#include <stdio.h>
#include "DBDLinkedList.h"

int main(void)
{
	List list;
	int data;
	ListInit(&list);

	for (int i = 0; i <= 8; i++)
	{
		LInsert(&list, i * 2);
	}

	// query items
	if (LFirst(&list, &data)) 
	{
		printf("%d ", data);

		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}

	printf("\n\n");

	// delete multiple of 4
	if (LFirst(&list, &data))
	{
		if (data % 4 == 0)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data % 4 == 0)
				LRemove(&list);
		}
	}

	// query items
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}

	printf("\n\n");

	system("pause");

	return 0;
}