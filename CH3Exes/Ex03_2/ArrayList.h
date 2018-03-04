#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#include "NameCard.h"

#define TRUE 1
#define FALSE 0

/* ArrayList의 정의 */
#define LIST_LEN 100
typedef NameCard* LData;

typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList;

/* ArrayList와 관련된 연산들 */
typedef ArrayList List;

void ListInit(List* plist);
void LInsert(List* plist, LData data);
int LFirst(List* plist, LData data);
int LNext(List* plist, LData data);

LData LRemove(List* plist);
int LCount(List* plist);

#endif