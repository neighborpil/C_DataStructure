#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree.h"

BTreeNode* MakeExpTree(char exp[]); // ���� ǥ����� ������ ���ڿ� ���·� �Է�, ����Ʈ���� ��Ʈ����� �ּҰ� ��ȯ
int EvaluateExpTree(BTreeNode* bt); // ����Ʈ���� ������ ����Ͽ� ����� ��ȯ

void ShowPrefixTypeExp(BTreeNode* bt);
void ShowInfixTypeExp(BTreeNode* bt);
void ShowPostfixTypeExp(BTreeNode* bt);

#endif // !__EXPRESSION_TREE_H__
