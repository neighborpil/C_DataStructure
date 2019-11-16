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

// �� ���� �ڽ� ��� �� ���� �켱������ �ڽ� ��� �ε��� ��ȯ
int  GetHiPriChildIdx(Heap* ph, int idx)
{
	if (GetLChildIdx(idx) > ph->numOfData)
		return 0;
	else if (GetLChildIdx(idx) == ph->numOfData)
		return GetLChildIdx(idx);
	else
	{
		// ���� �������� ���� �켱����
		if (ph->heapArr[GetLChildIdx(idx)].pr > ph->heapArr[GetRChildIdx(idx)].pr)
			return GetRChildIdx(idx);
		else
			return GetLChildIdx(idx);
	}
}

void HInsert(Heap* ph, HData data, Priority pr)
{
	int idx = ph->numOfData + 1; // �� ��尡 ����� �ε��� ��
	HeapElem nelem = { pr, data }; // �� ����� ���� �� �ʱ�ȭ

	// �� ��尡 ����� ��ġ�� ��Ʈ ����� ��ġ�� �ƴϸ� while�� �ݺ�
	while (idx != 1)
	{
		// �� ���� �θ� ����� �켱���� ��
		if (pr < (ph->heapArr[GetParentIdx(idx)].pr)) // �� ����� �켱������ ���ٸ�
		{
			// �θ� ��带 �� ���� ����, ������ ����
			ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
			// �� ��带 �� ���� �ø�, ������ �ø����� �ʰ� �ε��� ���� ����
			idx = GetParentIdx(idx);
		}
		else // �� ����� �켱������ ���� �ʴٸ�
			break;
	}

	ph->heapArr[idx] = nelem; // �� ��带 �迭�� ����
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
		if (lastElem.pr <= ph->heapArr[childIdx].pr) // ������ ���� �켱���� ��
			break; // ������ ����� �켱������ ������ �ݺ��� Ż��

		// ������ ��庸�� �켱������ ������, �񱳴�� ����� ��ġ�� �� ���� �ø�
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx; // ������ ��尡 ����� ��ġ������ �� ���� ����
							  // �ݺ��� Ż���ϸ� parentIdx�� ������ ����� ��ġ������ ����
	}

	ph->heapArr[parentIdx] = lastElem; // ������ ��� ġ�� ����
	ph->numOfData -= 1;
	return retData;
}