#include <stdio.h>

void HanoiTowerSolu(int num, int from, int by, int to)
{
	if (num == 1)
	{
		printf("원반 1을 %c에서 %c로 이동 \n", from, to);
	}
	else
	{
		HanoiTowerSolu(num - 1, from, to, by);
		printf("원반 %d을(를) %c에서 %c로 이동 \n", num, from, to);
		HanoiTowerSolu(num - 1, by, from, to);
	}
}

int main(void)
{
	// 막대A의 원반 3개를 막대B를 경유하여 막대C로 옮기기
	HanoiTowerSolu(3, 'A', 'B', 'C');

	system("pause");
	return 0;

}