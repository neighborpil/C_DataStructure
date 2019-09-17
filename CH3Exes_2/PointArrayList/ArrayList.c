#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist)
{
	plist->numOfData = 0;
	plist->curPosition = -1;
}

void LInsert(List* plist, LData data) 
{
	if (plist->curPosition == LIST_LEN)
	{
		puts("Couldn't insert number more!");
		return;
	}

	plist->arr[plist->numOfData++] = data;
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)
	{
		puts("There's no item in this list");
		return FALSE;
	}
	plist->curPosition = 0;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition == -1)
	{
		puts("Run LFirst first!");
		return FALSE;
	}

	plist->curPosition++;

	if (plist->curPosition == plist->numOfData)
	{
		return FALSE;
	}

	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List* plist)
{
	int currentData = plist->arr[plist->curPosition];

	for (int i = plist->curPosition; i < plist->numOfData-1; i++)
	{
		plist->arr[plist->curPosition] = plist->arr[plist->curPosition + 1];
	}

	plist->numOfData--;
	plist->curPosition--;

	return currentData;
}

int LCount(List* plist)
{
	return plist->numOfData;
}
