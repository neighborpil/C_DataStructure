#include <stdio.h>

int BSearchRecur(int ar[], int first, int end, int target)
{
	int mid;
	if (first > end)
		return -1;
	
	mid = (first + end) / 2;

	if (ar[mid] == target)
		return mid;
	else if (target < ar[mid])
		BSearchRecur(ar, first, mid - 1, target);
	else
		BSearchRecur(ar, mid + 1, end, target);
}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
	if (idx == -1)
		printf("Å½»ö ½ÇÆĞ! \n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º : %d \n", idx);

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 4);
	if (idx == -1)
		printf("Å½»ö ½ÇÆĞ! \n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º : %d \n", idx);

	system("pause");
	return 0;
}