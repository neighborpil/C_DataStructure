#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty(Queue* pq)
{
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = NULL;

	pq->rear->next = newNode;
	pq->rear = newNode;
}

Data Dequeue(Queue* pq)
{
	Node rNode;
	Data rData;


}
Data QPeek(Queue* pq);