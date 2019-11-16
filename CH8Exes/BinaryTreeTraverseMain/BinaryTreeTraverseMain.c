#include <stdio.h>
#include "BinaryTree.h"

void InorderTraverse(BTreeNode* bt);
void PreorderTraverse(BTreeNode* bt);
void PostorderTraverse(BTreeNode* bt);

int main(void)
{
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);

	InorderTraverse(bt1);
	printf("\n\n");
	PreorderTraverse(bt1);
	printf("\n\n");
	PostorderTraverse(bt1);

	return 0;
}

void InorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
		return;
	InorderTraverse(bt->left);
	printf("%d \n", GetData(bt));
	InorderTraverse(bt->right);
}

void PreorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
		return;
	printf("%d \n", GetData(bt));
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
		return;
	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	printf("%d \n", GetData(bt));
}