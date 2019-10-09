#include <stdio.h>
#include "DLinkedList.h"

#define SORTING TRUE

int Ascending(LData d1, LData d2);
int Descending(LData d1, LData d2);

int main(void)
{
	// creatting list
	List list;
	int data;
	ListInit(&list);

#if SORTING == TRUE
	SetSortRule(&list, Descending);
#endif

	// insert 5 items
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 44);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);

	// print all items
	printf("Total item count: %d \n", LCount(&list));


	if (LFirst(&list, &data))
	{
		printf("%d \n", data);

		while(LNext(&list, &data))
			printf("%d \n", data);
	}

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

	// print all items after deleting 22
	printf("Total item count: %d \n", LCount(&list));


	if (LFirst(&list, &data))
	{
		printf("%d \n", data);

		while (LNext(&list, &data))
			printf("%d \n", data);
	}

	printf("\n\n");

	system("pause");
}

int Descending(LData d1, LData d2)
{
	if (d1 > d2)
		return TRUE;
	else
		return FALSE;
}

int Ascending(LData d1, LData d2)
{
	if (d1 < d2)
		return TRUE;
	else
		return FALSE;
}