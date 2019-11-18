#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"

int DataPriorityComp(char* sentence1, char* sentence2)
{
	return strlen(sentence2) - strlen(sentence1);
}

int main(void)
{
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, "Good morning");
	PEnqueue(&pq, "Good afternoon ma'am");
	PEnqueue(&pq, "Good evening sir");

	while (!PQIsEmpty(&pq))
		printf("%s \n", PDequeue(&pq));

	return 0;
}