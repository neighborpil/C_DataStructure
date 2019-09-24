#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(void)
{
	int arr[10];
	int readCount = 0;
	int readData;

	while (TRUE)
	{
		printf("자연수 입력: ");
		scanf_s("%d", &readData, sizeof(readData));
		if (readData < 1)
			break;

		arr[readCount++] = readData;
	}

	for (int i=0; i < readCount; i++)
		printf("%d ", arr[i]);

	system("pause");

	return 0;
}