#ifndef __LINKED_LIST_BASE_STACK__
#define __LINKED_LIST_BASE_STACK__

#include "DLinkedList.h"

//#define TRUE 1
//#define FALSE 0

//typedef int Data;
//
//typedef struct _node
//{
//	Data data;
//	struct _node* next;
//} Node;

//typedef struct _listStack
//{
//	Node* head;
//} ListStack;

//typedef ListStack Stack;

typedef int Data;
typedef List Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

#endif // !__LINKED_LIST_BASE_STACK__
