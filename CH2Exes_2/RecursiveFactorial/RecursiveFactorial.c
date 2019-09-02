#include <stdio.h>

int Factorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * Factorial(n - 1);
}

int main(void)
{
	for (int i = 1; i < 6; i++)
		printf("%d! == %d \n", i, Factorial(i));

	system("pause");

	return 0;
}