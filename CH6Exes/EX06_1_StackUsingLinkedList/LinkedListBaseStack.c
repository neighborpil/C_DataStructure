#include <stdio.h>
#include <stdlib.h>
#include "LinkedListBaseStack.h"
#include "DLinkedList.h"

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
	if (SIsEmpty(pstack))
	{
		puts("Stack is Empty");
		exit(-1);
	}
	
	Node* rNode = pstack->head;
	Data rdata = rNode->data;

	pstack->head = pstack->head->next;
	free(rNode);

	return rdata;
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