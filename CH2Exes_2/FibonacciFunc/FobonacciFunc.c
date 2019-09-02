#include <stdio.h>

int Fibo(int n)
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
	{
		return Fibo(n - 1) + Fibo(n - 2);
	}
}

int main(void)
{

	int result = 0;
	for (int i = 1; i < 10; i++)
	{
		result = Fibo(i);
		printf("Fibonacci %d = %d \n", i, result);
	}


	system("pause");
}