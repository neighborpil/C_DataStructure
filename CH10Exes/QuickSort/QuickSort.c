#include <stdio.h>

int MedianOfThree(int arr[], int left, int right);
void Swap(int arr[], int idx1, int idx2);
int Partition(int arr[], int left, int right);
void QuickSort(int arr[], int left, int right);


int main(void)
{
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
	// int arr[3] = { 3, 3, 3 };
	//int arr[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

	int len = sizeof(arr) / sizeof(int);
	
	QuickSort(arr, 0, len - 1);

	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
}

int MedianOfThree(int arr[], int left, int right)
{
	int samples[3] = { left, (left + right) / 2, right }; // �ε��� ������ �迭�� ����

	if (arr[samples[0]] > arr[samples[1]])
		Swap(samples, 0, 1);

	if (arr[samples[1]] > arr[samples[2]])
		Swap(samples, 1, 2);

	if (arr[samples[0]] > arr[samples[1]])
		Swap(samples, 0, 1);

	return samples[1];
}

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
	//int pivot = arr[left]; // �ǹ��� ��ġ�� ���� ����
	//int pivot = arr[(left + right) / 2]; // �ǹ��� ��ġ�� ���� ����
	int pIdx = MedianOfThree(arr, left, right); // �ǹ��� ����
	int pivot = arr[pIdx];

	int low = left + 1;
	int high = right;

	Swap(arr, left, pIdx);

	printf("�ǹ�: %d \n", pivot);

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