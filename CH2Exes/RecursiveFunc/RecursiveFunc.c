#include <stdio.h>

void Recursive(int num)
{
	if (num <= 0) // Å»Ãâ Á¶°Ç
		return;	// Å»Ãâ!!
	printf("Recursive call %d \n", num);
	Recursive(num - 1);
}

int main(void)
{
	Recursive(3);

	system("pause");
	return 0;
}