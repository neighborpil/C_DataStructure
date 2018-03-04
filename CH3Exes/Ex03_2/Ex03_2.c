#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
	List list;
	NameCard* pCard;
	ListInit(&list);

	pCard = MakeNameCard("������", "333-3333");
	LInsert(&list, pCard);

	pCard = MakeNameCard("������", "111-3333");
	LInsert(&list, pCard);

	pCard = MakeNameCard("������", "222-3333");
	LInsert(&list, pCard);

	if (LFirst(&list, &pCard))
	{
		//������ ���� ��ȸ ���
		if (NameCompare(pCard, "������"))
		{
			ShowNameCardInfo(pCard);
		}
		else
		{
			while (LNext(&list, &pCard))
			{
				if (NameCompare(pCard, "������"))
				{
					ShowNameCardInfo(pCard);
					break;
				}
			}
		}
	}

	// ������ ���� ��ȸ �� ����
	if (LFirst(&list, &pCard))
	{
		if (NameCompare(pCard, "������"))
		{
			ChangePhoneNum(pCard, "333-3333");
		}
		else
		{
			while (LNext(&list, &pCard))
			{
				if (NameCompare(pCard, "������"))
				{
					ChangePhoneNum(pCard, "333-3333");
					break;
				}

			}
		}
	}

	//������ ���� ��ȸ �� ����
	if (LFirst(&list, &pCard))
	{
		if (NameCompare(pCard, "������"))
		{
			pCard = LRemove(&list);
			free(pCard);
		}
		else
		{
			while (LNext(&list, &pCard))
			{
				if (NameCompare(pCard, "������"))
				{
					pCard = LRemove(&list);
					free(pCard);
				}
			}
		}
	}

	puts("");

	// ��ü ���
	printf("���� ������ �� : %d \n", LCount(&list));

	if (LFirst(&list, &pCard))
	{
		ShowNameCardInfo(pCard);

		while (LNext(&list, &pCard))
		{
			ShowNameCardInfo(pCard);
		}
	}

	system("pause");
	return 0;
}