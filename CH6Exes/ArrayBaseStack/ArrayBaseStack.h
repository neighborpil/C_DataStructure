#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data;

typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack* pstack);
void SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
void SPop(Stack* pstack);
void SPeek(Stack* pstack);

#endif // !__AB_STACK_H__
