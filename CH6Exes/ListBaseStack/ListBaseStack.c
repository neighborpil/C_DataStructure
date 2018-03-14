#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack* pstack)
{
	pstack->head = NULL;
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head = newNode;
}

Data SPop(Stack* pstack)
{
	Node* tempNode;
	Data tempData;

	if (SIsEmpty(pstack))
	{
		puts("Stack is Empty");
		exit(-1);
	}

	tempNode = pstack->head;
	tempData = pstack->head->data;

	pstack->head = pstack->head->next;

	free(tempNode);
	return tempData;
}

Data SPeek(Stack* pstack)
{
	if (SIsEmpty(pstack))
	{
		puts("Stack is Empty");
		exit(-1);
	}
	return pstack->head->data;
}