#include "SimpleHeap.h"

void HeapInit(Heap* ph)
{
	ph->numOfData = 0;
}

int HIsEmpty(Heap* ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIdx(int idx) // return parent index value
{
	return idx / 2;
}

int GetLChildIdx(int idx)
{
	return idx * 2;
}

int GetRChildIdx(int idx)
{
	return GetLChildIdx(idx) + 1;
}

// 두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 반환
int  GetHiPriChildIdx(Heap* ph, int idx)
{
	if (GetLChildIdx(idx) > ph->numOfData)
		return 0;
	else if (GetLChildIdx(idx) == ph->numOfData)
		return GetLChildIdx(idx);
	else
	{
		// 값이 작을수록 높은 우선순위
		if (ph->heapArr[GetLChildIdx(idx)].pr > ph->heapArr[GetRChildIdx(idx)].pr)
			return GetRChildIdx(idx);
		else
			return GetLChildIdx(idx);
	}
}

void HInsert(Heap* ph, HData data, Priority pr)
{
	int idx = ph->numOfData + 1; // 새 노드가 저장될 인덱스 값
	HeapElem nelem = { pr, data }; // 새 노드의 생성 및 초기화

	// 새 노드가 저장될 위치가 루트 노드의 위치가 아니면 while문 반복
	while (idx != 1)
	{
		// 새 노드와 부모 노드의 우선순위 비교
		if (pr < (ph->heapArr[GetParentIdx(idx)].pr)) // 새 노드의 우선순위가 높다면
		{
			// 부모 노드를 한 레벨 내림, 실제로 내림
			ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
			// 새 노드를 한 레벨 올림, 실제로 올리지는 않고 인덱스 값만 갱신
			idx = GetParentIdx(idx);
		}
		else // 새 노드의 우선순위가 높지 않다면
			break;
	}

	ph->heapArr[idx] = nelem; // 새 노드를 배열에 저장
	ph->numOfData += 1;
}
HData HDelete(Heap* ph)
{
	HData retData = (ph->heapArr[1]).data;
	HeapElem lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIdx(ph, parentIdx))
	{
		if (lastElem.pr <= ph->heapArr[childIdx].pr) // 마지막 노드와 우선순위 비교
			break; // 마지막 노드의 우선순위가 높으면 반복문 탈출

		// 마지막 노드보다 우선순위가 높으니, 비교대상 노드의 위치를 한 레벨 올림
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx; // 마지막 노드가 저장될 위치정보를 한 레벨 내림
							  // 반복문 탈출하면 parentIdx에 마지막 노드의 위치정보가 저장
	}

	ph->heapArr[parentIdx] = lastElem; // 마지막 노드 치종 저장
	ph->numOfData -= 1;
	return retData;
}