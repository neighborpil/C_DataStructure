#include <stdio.h>
#include "CircularListBaseStack.h"

int main(void)
{
	Stack stack;
	StackInit(&stack);

	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);

	if (!SIsEmpty(&stack))
		printf("Peek: %d \n", SPeek(&stack));

	printf("\n\n");

	while (TRUE)
	{
		if (SIsEmpty(&stack))
			break;

		printf("Pop: %d \n", SPop(&stack));
	}

	return 0;
}