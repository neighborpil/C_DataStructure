#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct _node
{
	int data;
	struct _node* next;
} Node;

int main(void)
{
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;

	Node* newNode = NULL;
	int readData;

	// receive data
	while (TRUE)
	{
		printf("자연수 입력:");
		scanf_s("%d", &readData, sizeof(readData));
		if (readData < 1)
			break;

		// add a node
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;

		tail = newNode;
	}

	printf("\n");

	// print received data
	printf("print all data \n");
	if (head == NULL)
	{
		printf("No data is saved.\n");
	}
	else 
	{
		cur = head;

		printf("%d \n", cur->data);

		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d \n", cur->data);
		}
	}

	printf("\n");

	// release memory
	if (head == NULL)
		return 0;
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("Delete %d \n", head->data);
		free(delNode);

		while (cur->next != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("Delete %d \n", delNode->data);
			free(delNode);
		}
	}

	system("pause");

	return 0;
}