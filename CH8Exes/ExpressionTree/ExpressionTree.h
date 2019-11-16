#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree.h"

BTreeNode* MakeExpTree(char exp[]); // 후위 표기법의 수식을 문자열 형태로 입력, 수식트리의 루트노드의 주소값 반환
int EvaluateExpTree(BTreeNode* bt); // 수식트리의 수식을 계산하여 결과를 반환

void ShowPrefixTypeExp(BTreeNode* bt);
void ShowInfixTypeExp(BTreeNode* bt);
void ShowPostfixTypeExp(BTreeNode* bt);

#endif // !__EXPRESSION_TREE_H__
