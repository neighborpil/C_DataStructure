#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

int main(void)
{
	Stack stack;
	StackInit(&stack);

	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);

	if(!SIsEmpty(&stack))
		printf("Peek data: %d \n", SPeek(&stack));

	printf("\n\n");

	while (TRUE)
	{
		if (SIsEmpty(&stack))
			break;
		printf("Peek data: %d \n", SPop(&stack));
	}

	return 0;
}