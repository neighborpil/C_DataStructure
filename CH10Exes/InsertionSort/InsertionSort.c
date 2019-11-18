#include <stdio.h>

// 삽입 정렬(Insertion Sort): O(n²)

void InserSort(int arr[], int n);

int main(void)
{
	int arr[5] = { 5,3, 2, 4, 1 };
	
	InserSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 5; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
}

void InserSort(int arr[], int n)
{
	int i, j;
	int insData;

	for (i = 1; i < n; i++)
	{
		insData = arr[i]; // 정렬 대상을 insData에 저장

		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > insData)
				arr[j + 1] = arr[j]; // 비교 대상 한칸 밀기
			else
				break;
		}

		arr[j + 1] = insData;
	}
}