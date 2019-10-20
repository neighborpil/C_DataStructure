#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

Employee* CreateEmployee(int number, char* name);
Employee* WhosNightDuty(List* plist, char* name, int day);
void ShowEmployeeInfo(Employee* emp);


int main(void)
{
	Employee* pemp;

	// 리스트 생성 및 초기화
	List list;
	ListInit(&list);

	// 4명 데이터 저장
	pemp = CreateEmployee(1, "Terry");
	LInsert(&list, pemp);

	pemp = CreateEmployee(2, "Jery");
	LInsert(&list, pemp);

	pemp = CreateEmployee(3, "Hary");
	LInsert(&list, pemp);

	pemp = CreateEmployee(4, "Sunny");
	LInsert(&list, pemp);

	// Terry이후 3일 뒤 당직자는?
	pemp = WhosNightDuty(&list, "Terry", 3);
	ShowEmployeeInfo(pemp);

	// Sunny이후 3일 뒤 당직자는?
	pemp = WhosNightDuty(&list, "Sunny", 15);
	ShowEmployeeInfo(pemp);

	// 전체 메모리 소멸
	if (LFirst(&list, &pemp))
	{
		free(pemp);

		for (int i = 0; i < LCount(&list) - 1; i++)
		{
			if (LNext(&list, &pemp))
			{
				free(pemp);
			}
		}
	}

	system("pause");

	return 0;
}

Employee* CreateEmployee(int employeeNumber, char* name)
{
	Employee* pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = employeeNumber;
	strcpy_s(pemp->name, strlen(name) + 1, name);

	return pemp;
}

Employee* WhosNightDuty(List* plist, char* name, int days)
{
	Employee* ret;

	int num = LCount(plist);

	// 이름 찾기
	LFirst(plist, &ret);

	if (strcmp(ret->name, name) != 0) // << 오류 발생 부분
	{
		for (int i = 0; i < num - 1; i++)
		{
			LNext(plist, &ret);


			if (strcmp(ret->name, name) == 0)
				break;
		}
	}

	// 그 뒤 며칠 뒤
	for (int i = 0; i < days; i++)
	{
		LNext(plist, &ret);
	}

	return ret;
}

void ShowEmployeeInfo(Employee* emp)
{
	printf("Employee name: %d \n", emp->empNum);
	printf("Employee name: %s \n", emp->name);
}