#include <stdio.h>

void QuickSort(int arr[], int left, int right);
int Partition(int arr[], int left, int right);
int MedianOfThree(int arr[], int left, int right);
void Swap(int arr[], int idx1, int idx2);

int main(void)
{
	int arr[] = { 2, 8, 1, 7, 3, 4, 5 };
	//int arr[] = { 3, 3, 3 };
	int length = sizeof(arr) / sizeof(int);

	QuickSort(arr, 0, length - 1);

	for (int i = 0; i < length; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
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

int Partition(int arr[], int left, int right) // 첫번째와 arr의 길이 - 1
{
	//int pivot = arr[left];
	int pivotIndex = MedianOfThree(arr, left, right);
	Swap(arr, left, pivotIndex);
	int pivot = arr[left];

	int low = left + 1;
	int high = right;

	while (low <= high) // 교차되지 않을 때까지 반복
	{
		// 피벗보다 큰 값을 찾는 과정
		while (pivot >= arr[low] && low <= right)
			low++;

		while (pivot < arr[high] && high >= (left + 1))
			high--;

		if (low <= high) // 교차되지 않은 상태라면 스왑
			Swap(arr, low, high);
	}

	Swap(arr, left, high);

	return high;
}

int MedianOfThree(int arr[], int left, int right)
{
	int samples[] =
	{
		left,
		(left + right) / 2,
		right
	};

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


