#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircularQueue.h"

#define CUS_COME_TERM 15 // ���� �ֹ� ���� : 15��

#define CHE_BUR 0 // ġ����� ���
#define BUL_BUR 1 // �Ұ����� ���
#define DUB_BUR 2 // ������� ���

#define CHE_TERM 12 // ġ����� ���� �ð�: �� ����
#define BUL_TERM 15 // �Ұ����� ���� �ð�: �� ����
#define DUB_TERM 25 // ������� ���� �ð�: �� ����

#define SIM_TIME 3600 //�ùķ��̼� �ð�

int main(void)
{
	int makeProc = 0;
	int cheOrder = 0, bulOrder = 0, dubOrder = 0;

	Queue que;

	QueueInit(&que);
	srand(time(NULL));

	// �Ʒ��� for������ 1ȸ�� ȸ���� 1���� �帧�� �ǹ���
	for (int sec = 0; sec < SIM_TIME; sec++)
	{
		if (sec % CUS_COME_TERM == 0)
		{
			switch (rand() % 3)
			{
			case CHE_BUR:
				Enqueue(&que, BUL_TERM);
				cheOrder += 1;
				break;
			case BUL_BUR:
				Enqueue(&que, CHE_TERM);
				bulOrder += 1;
				break;
			case DUB_BUR:
				Enqueue(&que, DUB_TERM);
				dubOrder += 1;
				break;
			}
		}

		if (makeProc <= 0 && !QIsEmpty(&que))
			makeProc = Dequeue(&que);

		makeProc--;
	}

	printf("Simulation Report \n");
	printf(" - Cheese burger: %d \n", cheOrder);
	printf(" - Bulgogi burger: %d \n", bulOrder);
	printf(" - Double burger: %d \n", dubOrder);
	printf(" - Waiting room size: %d \n", QUE_LEN);

	return 0;
}