#ifndef __USEFUL_hEAP_H__
#define __USEFUL_hEAP_H__

#define TRUE 1
#define FALSE 0

// ÈüÀÇ Á¤ÀÇ
#define HEAP_LEN 100

typedef int HData;

typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap
{
	PriorityComp* comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
} Heap;


// Èü °ü·Ã ¿¬»ê
void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);
HData HDelete(Heap* ph);

#endif // !__USEFUL_hEAP_H__
