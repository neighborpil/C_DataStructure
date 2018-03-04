#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
	List list;
	NameCard* pCard;
	ListInit(&list);

	pCard = MakeNameCard("이진수", "333-3333");
	LInsert(&list, pCard);

	pCard = MakeNameCard("한진수", "111-3333");
	LInsert(&list, pCard);

	pCard = MakeNameCard("김진수", "222-3333");
	LInsert(&list, pCard);

	if (LFirst(&list, &pCard))
	{
		//한진수 정보 조회 출력
		if (NameCompare(pCard, "이진수"))
		{
			ShowNameCardInfo(pCard);
		}
		else
		{
			while (LNext(&list, &pCard))
			{
				if (NameCompare(pCard, "이진수"))
				{
					ShowNameCardInfo(pCard);
					break;
				}
			}
		}
	}

	// 이진수 정보 조회 후 변경
	if (LFirst(&list, &pCard))
	{
		if (NameCompare(pCard, "한진수"))
		{
			ChangePhoneNum(pCard, "333-3333");
		}
		else
		{
			while (LNext(&list, &pCard))
			{
				if (NameCompare(pCard, "한진수"))
				{
					ChangePhoneNum(pCard, "333-3333");
					break;
				}

			}
		}
	}

	//김진수 정보 조회 후 삭제
	if (LFirst(&list, &pCard))
	{
		if (NameCompare(pCard, "김진수"))
		{
			pCard = LRemove(&list);
			free(pCard);
		}
		else
		{
			while (LNext(&list, &pCard))
			{
				if (NameCompare(pCard, "김진수"))
				{
					pCard = LRemove(&list);
					free(pCard);
				}
			}
		}
	}

	puts("");

	// 전체 출력
	printf("현재 데이터 수 : %d \n", LCount(&list));

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