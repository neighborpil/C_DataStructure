#include <stdio.h>

void HanoiTowerSolu(int num, int from, int by, int to)
{
	if (num == 1)
	{
		printf("���� 1�� %c���� %c�� �̵� \n", from, to);
	}
	else
	{
		HanoiTowerSolu(num - 1, from, to, by);
		printf("���� %d��(��) %c���� %c�� �̵� \n", num, from, to);
		HanoiTowerSolu(num - 1, by, from, to);
	}
}

int main(void)
{
	// ����A�� ���� 3���� ����B�� �����Ͽ� ����C�� �ű��
	HanoiTowerSolu(3, 'A', 'B', 'C');

	system("pause");
	return 0;

}