#include <stdio.h>
#include "CLinkedList.h"

#define _CRTDBG_MAP_ALLOC // Memory leaking check
#include <crtdbg.h>


Employee* CreateEmployee(int number, char* name);
int RemoveEmployee(Employee* employee);
int GetNightDutyPerson(List* list, char* name, int days, Employee* nextDutyPerson);
int IsSameName(char* name1, char* name2);
Employee* GetNextDutyPerson(List* list, Employee* dutyman, int days);

int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // checking the memeory leak at the debug mode

	List list;
	Data data;
	ListInit(&list);

	Employee* employee1 = CreateEmployee(1, "Steave");
	Employee* employee2 = CreateEmployee(2, "Steave2");
	Employee* employee3 = CreateEmployee(3, "Steave3");
	Employee* employee4 = CreateEmployee(4, "Steave4");

	LInsert(&list, *employee1);
	LInsert(&list, *employee2);
	LInsert(&list, *employee3);
	LInsert(&list, *employee4);


	if (LFirst(&list, &data)) 
	{
		printf("%d, %s \n", data.number, data.name);

		int listItemCount = LCount(&list);

		for(int i=0; i<listItemCount - 1; i++)
		{
			LNext(&list, &data);
			printf("%d, %s \n", data.number, data.name);
		}
	}

	int days = 3;

	Data nextDutyPerson;
	GetNightDutyPerson(&list, "Steave", days, &nextDutyPerson);

	printf("Next dutyman after %d days: %s \n", days, nextDutyPerson.name);

	RemoveEmployee(employee1);
	RemoveEmployee(employee2);
	RemoveEmployee(employee3);

	system("pause");
	return 0;
}

Employee* CreateEmployee(int number, char* name)
{
	Employee* newEmployee = (Employee*)malloc(sizeof(Employee));

	newEmployee->number = number;
	int newNameLength = strlen(name) + 1;

	newEmployee->name = (char*)malloc(sizeof(char)*newNameLength);
	strcpy_s(newEmployee->name, newNameLength, name);

	return newEmployee;
}

int RemoveEmployee(Employee* employee)
{
	int employeeNumber = employee->number;
	free(employee->name);
	free(employee);

	return employeeNumber;
}

int GetNightDutyPerson(List* list, char* name, int days, Employee* nextDutyPerson)
{
	//printf("%s ", name);
	char* searchName = name;
	int daysAfter = days;

	Data dutyMan;

	// lcount
	int listItemCount = LCount(list);
	if (listItemCount == 0)
		return FALSE;

	// lfirst
	if (LFirst(&list, &dutyMan))  
	{
		if (IsSameName(dutyMan.name, searchName))
		{
			nextDutyPerson = GetNextDutyPerson(&list, &dutyMan, daysAfter);

			return TRUE;
		}

		while (LNext(&list, &dutyMan)) 
		{
			if (IsSameName(dutyMan.name, searchName))
			{
				Data* searchedPerson = GetNextDutyPerson(&list, &dutyMan, daysAfter);

				nextDutyPerson->name = searchedPerson->name;
				nextDutyPerson->number = searchedPerson->name;
				return TRUE;
			}
		}
	}
	return FALSE;
}

int IsSameName(char* name1, char* name2)
{
	if (name1 == NULL || name2 == NULL)
		return FALSE;

	int nameLength1 = strlen(name1);
	int nameLength2 = strlen(name2);

	if(nameLength1 != nameLength2)
		return FALSE;


	int result = strcmp(name1, name2);

	if(result == 0)
		return TRUE;

	return FALSE;
}

Employee* GetNextDutyPerson(List* list, Employee* dutyman, int days)
{
	Employee* nextDutyMan = dutyman;
	for (int i = 0; i < days; i++)
	{
		LNext(list, nextDutyMan);
	}

	return nextDutyMan;
}