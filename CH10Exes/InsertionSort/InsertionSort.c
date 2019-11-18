#include <stdio.h>

// ���� ����(Insertion Sort): O(n��)

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
		insData = arr[i]; // ���� ����� insData�� ����

		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > insData)
				arr[j + 1] = arr[j]; // �� ��� ��ĭ �б�
			else
				break;
		}

		arr[j + 1] = insData;
	}
}