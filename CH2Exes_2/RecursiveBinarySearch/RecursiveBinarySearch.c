#include <stdio.h>

int BSearchRecur(int ar[], int first, int last, int target)
{
	if (first > last)
		return -1;
	int mid = (first + last) / 2;

	if (target == ar[mid])
		return mid;
	else if (target < ar[mid])
		return BSearchRecur(ar, first, mid - 1, target);
	else
		return BSearchRecur(ar, mid + 1, last, target);
}

int main(void)
{ 
	int ar[] = { 1, 3, 6, 9, 10, 52, 124 };

	int num = 1;
	int result = BSearchRecur(ar, 0, sizeof(ar) / sizeof(int), num);
	printf("%d index is %d \n", num, result);

	num = 124;
	result = BSearchRecur(ar, 0, sizeof(ar) / sizeof(int), num);
	printf("%d index is %d \n", num, result);

	num = 4;
	result = BSearchRecur(ar, 0, sizeof(ar) / sizeof(int), num);
	printf("%d index is %d \n", num, result);

	system("pause");

	return 1;
}