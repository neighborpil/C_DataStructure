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

	// ����Ʈ ���� �� �ʱ�ȭ
	List list;
	ListInit(&list);

	// 4�� ������ ����
	pemp = CreateEmployee(1, "Terry");
	LInsert(&list, pemp);

	pemp = CreateEmployee(2, "Jery");
	LInsert(&list, pemp);

	pemp = CreateEmployee(3, "Hary");
	LInsert(&list, pemp);

	pemp = CreateEmployee(4, "Sunny");
	LInsert(&list, pemp);

	// Terry���� 3�� �� �����ڴ�?
	pemp = WhosNightDuty(&list, "Terry", 3);
	ShowEmployeeInfo(pemp);

	// Sunny���� 3�� �� �����ڴ�?
	pemp = WhosNightDuty(&list, "Sunny", 15);
	ShowEmployeeInfo(pemp);

	// ��ü �޸� �Ҹ�
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

	// �̸� ã��
	LFirst(plist, &ret);

	if (strcmp(ret->name, name) != 0) // << ���� �߻� �κ�
	{
		for (int i = 0; i < num - 1; i++)
		{
			LNext(plist, &ret);


			if (strcmp(ret->name, name) == 0)
				break;
		}
	}

	// �� �� ��ĥ ��
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