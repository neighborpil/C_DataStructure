#include <stdio.h>

void Swap(int arr[], int idx1, int idx2);
int Partition(int arr[], int left, int right);
void QuickSort(int arr[], int left, int right);


int main(void)
{
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
	// int arr[3] = { 3, 3, 3 };

	int len = sizeof(arr) / sizeof(int);
	
	QuickSort(arr, 0, len - 1);

	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
}

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left]; // �ǹ��� ��ġ�� ���� ����
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		// �ǹ����� ū ���� ã�� ����
		while (pivot >= arr[low] && low <= high)
			low++; // low�� ���������� �̵�

		// �ǹ����� ���� ���� ã�� ����
		while (pivot <= arr[high] && high >= (left + 1))
			high--; // high�� �������� �̵�

		// �������� ���� ���¶�� Swap ����
		if (low <= high)
			Swap(arr, low, high);
	}

	Swap(arr, left, high); // �ǹ��� high�� ����Ű�� ��� ��ȯ

	return high; // �Ű��� �ǹ��� ��ġ���� ��ȭ
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}