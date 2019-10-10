#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{
	// creating circular linkedlist and initialize
	List list;
	Data data;
	ListInit(&list);

	// inserting 5 items;
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);

	// print items in the list for 3 times
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		int count = LCount(&list) * 3 - 1;
		for (int i = 0; i < count; i++)
		{
			if (LNext(&list, &data))
			{
				printf("%d ", data);
			}
		}
	}

	printf("\n\n");

	// deleting multiples of 2
	int nodeNum = LCount(&list);

	if (nodeNum != 0)
	{
		LFirst(&list, &data);
		if (data % 2 == 0)
			LRemove(&list);

		for (int i = 0; i < nodeNum - 1; i++)
		{
			LNext(&list, &data);
			if (data % 2 == 0)
				LRemove(&list);
		}
	}

	// print items in the list for 3 times after deleting
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		int count = LCount(&list) - 1;
		for (int i = 0; i < count; i++)
		{
			if (LNext(&list, &data))
			{
				printf("%d ", data);
			}
		}
	}

	printf("\n\n");
	system("pause");
}