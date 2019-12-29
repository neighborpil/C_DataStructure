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
	int pivot = arr[left]; // 피벗의 위치는 가장 왼쪽
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		// 피벗보다 큰 값을 찾는 과정
		while (pivot >= arr[low] && low <= high)
			low++; // low를 오른쪽으로 이동

		// 피벗보다 작은 값을 찾는 과정
		while (pivot <= arr[high] && high >= (left + 1))
			high--; // high를 왼쪽으로 이동

		// 교차되지 않은 상태라면 Swap 실행
		if (low <= high)
			Swap(arr, low, high);
	}

	Swap(arr, left, high); // 피벗과 high가 가리키는 대상 교환

	return high; // 옮겨진 피벗의 위치정보 교화
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