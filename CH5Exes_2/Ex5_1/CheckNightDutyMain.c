#include <stdio.h>
#include "CLinkedList.h"

#ifdef _DEBUG
#include <crtdbg.h>
#ifdef malloc
#undef malloc

#endif
#define malloc(s)(_malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__))

#endif

Employee* CreateEmployee(int number, char* name);
int RemoveEmployee(Employee* employee);

int main(void)
{
	List list;
	Data data;
	ListInit(&list);

	Employee* employee1 = CreateEmployee(1, "Steave");

	printf("%d %s \n", employee1->number, employee1->name);


	Employee* employee2 = CreateEmployee(2, "Steave2");

	printf("%d %s \n", employee2->number, employee2->name);

	RemoveEmployee(employee2);

	//system("pause");
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
	//free(employee->name);
	//free(employee);

	return employeeNumber;
}
