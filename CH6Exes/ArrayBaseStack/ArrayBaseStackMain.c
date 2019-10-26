#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void)
{
	// Creation and initialization
	Stack stack;
	StackInit(&stack);

	// Insert data
	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);

	// Peek
	int data = SPeek(&stack);
	printf("Peek data: %d \n", data);

	printf("\n\n");

	while (!SIsEmpty(&stack))
		printf("Pop data: %d \n", SPop(&stack));

	return 0;
}