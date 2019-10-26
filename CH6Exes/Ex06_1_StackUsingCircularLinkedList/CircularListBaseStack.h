#ifndef __CIRCULAR_LINKEDLIST_BASE_STACK_H__
#define __CIRCULAR_LINKEDLIST_BASE_STACK_H__
#include "CLinkedList.h"


#define TRUE 1
#define FALSE 0

//typedef int Data;
//
//typedef struct _node
//{
//	Data data;
//	struct _node* next;
//} Node;

typedef struct _listStack
{
	List* plist;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

#endif // ! __CIRCULAR_LINKEDLIST_BASE_STACK_H__