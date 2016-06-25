#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree3.h"
#include "BinarySearchTree3.h"
#include "AVLRebalance.h"


/////////////User ����/////////////////
void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

BTreeNode* BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	BTreeNode * pNode = NULL;    // parent node
	BTreeNode * cNode = *pRoot;    // current node
	BTreeNode * nNode = NULL;    // new node

								 // ���ο� ��尡 �߰��� ��ġ�� ã�´�.
	while (cNode != NULL)
	{
		if (strcmp(data, GetData(cNode)) == 0)
			return NULL;    // Ű�� �ߺ��� ������� ����

		pNode = cNode;

		if (strcmp(GetData(cNode), data) > 0)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	// pNode�� ���� ��忡 �߰��� �� ����� ����
	nNode = MakeBTreeNode();    // �� ����� ����
	SetData(nNode, data);    // �� ��忡 ������ ����

							 // pNode�� ���� ��忡 �� ��带 �߰�
	if (pNode != NULL)    // �� ��尡 ��Ʈ ��尡 �ƴ϶��,
	{
		if (strcmp(data, GetData(pNode)) < 0)
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else    // �� ��尡 ��Ʈ �����,
	{
		*pRoot = nNode;
	}

	*pRoot = Rebalance(pRoot);	// ��� �߰� �� ���뷱��

	return nNode;
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode * cNode = bst;    // current node
	BSTData cd;    // current data

	while (cNode != NULL)
	{
		cd = GetData(cNode);

		if (strcmp(target, cd) == 0)
			return cNode;
		else if (strcmp(target, cd) < 0)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return NULL;
}

BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target)
{
	// ���� ����� ��Ʈ ����� ��츦 ������ ����ؾ� �Ѵ�.

	BTreeNode * pVRoot = MakeBTreeNode();    // ���� ��Ʈ ���;

	BTreeNode * pNode = pVRoot;    // parent node
	BTreeNode * cNode = *pRoot;    // current node
	BTreeNode * dNode;    // delete node

						  // ��Ʈ ��带 pVRoot�� ����Ű�� ����� ������ ���� ��尡 �ǰ� �Ѵ�.
	ChangeRightSubTree(pVRoot, *pRoot);

	// ���� ����� ������ ��� Ž��
	while (cNode != NULL && strcmp(GetData(cNode), target) != 0)
	{
		pNode = cNode;

		if (strcmp(target, GetData(cNode)) < 0)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL)    // ���� ����� �������� �ʴ´ٸ�,
		return NULL;

	dNode = cNode;    // ���� ����� dNode�� ����Ű�� �Ѵ�.

					  // ù ��° ���: ������ ��尡 �ܸ� ����� ���
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	// �� ��° ���: �ϳ��� �ڽ� ��带 ���� ���
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode * dcNode;    // delete node�� �ڽ� ���

		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	// �� ��° ���: �� ���� �ڽ� ��带 ��� ���� ���
	else
	{
		BTreeNode * mNode = GetRightSubTree(dNode);    // mininum node
		BTreeNode * mpNode = dNode;    // mininum node�� �θ� ���
		char delData[100];

		// ������ ��带 ��ü�� ��带 ã�´�.
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		// ��ü�� ��忡 ����� ���� ������ ��忡 �����Ѵ�.
		strcpy(delData, GetData(dNode));    // ���� �� ������ ���
		SetData(dNode, GetData(mNode));

		// ��ü�� ����� �θ� ���� �ڽ� ��带 �����Ѵ�.
		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);    // ��� ������ ����
	}

	// ������ ��尡 ��Ʈ ����� ��쿡 ���� ó��
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot);

	*pRoot = Rebalance(pRoot); 	// ��� ���� �� ���뷱��!
	return dNode;
}

void ShowIntData(int data)
{
	printf("%d\n", data);
}

void BSTShowAll(BTreeNode * bst)
{
	InorderTraverse(bst, ShowIntData);
}









//////////////Word ����//////////////

void BSTMakeAndInit1(WordNode ** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData1(WordNode * bst)
{
	return GetData1(bst);
}

WordNode* BSTInsert1(WordNode ** pRoot, BSTData data)
{
	WordNode * pNode = NULL;    // parent node
	WordNode * cNode = *pRoot;    // current node
	WordNode * nNode = NULL;    // new node

								 // ���ο� ��尡 �߰��� ��ġ�� ã�´�.
	while (cNode != NULL)
	{
		if (strcmp(data, GetData1(cNode)) == 0)
			return NULL;    // Ű�� �ߺ��� ������� ����

		pNode = cNode;

		if (strcmp(GetData1(cNode), data) > 0)
			cNode = GetLeftSubTree1(cNode);
		else
			cNode = GetRightSubTree1(cNode);
	}

	// pNode�� ���� ��忡 �߰��� �� ����� ����
	nNode = MakeWordNode1();    // �� ����� ����
	SetData1(nNode, data);    // �� ��忡 ������ ����

							 // pNode�� ���� ��忡 �� ��带 �߰�
	if (pNode != NULL)    // �� ��尡 ��Ʈ ��尡 �ƴ϶��,
	{
		if (strcmp(data, GetData1(pNode)) < 0)
			MakeLeftSubTree1(pNode, nNode);
		else
			MakeRightSubTree1(pNode, nNode);
	}
	else    // �� ��尡 ��Ʈ �����,
	{
		*pRoot = nNode;
	}

	*pRoot = Rebalance1(pRoot);	// ��� �߰� �� ���뷱��

	return nNode;
}

WordNode * BSTSearch1(WordNode * bst, BSTData target)
{
	WordNode * cNode = bst;    // current node
	BSTData cd;    // current data

	while (cNode != NULL)
	{
		cd = GetData1(cNode);

		if (strcmp(target, cd) == 0)
			return cNode;
		else if (strcmp(target, cd) < 0)
			cNode = GetLeftSubTree1(cNode);
		else
			cNode = GetRightSubTree1(cNode);
	}

	return NULL;
}

WordNode * BSTRemove1(WordNode ** pRoot, BSTData target)
{
	// ���� ����� ��Ʈ ����� ��츦 ������ ����ؾ� �Ѵ�.

	WordNode * pVRoot = MakeWordNode1();    // ���� ��Ʈ ���;

	WordNode * pNode = pVRoot;    // parent node
	WordNode * cNode = *pRoot;    // current node
	WordNode * dNode;    // delete node

						  // ��Ʈ ��带 pVRoot�� ����Ű�� ����� ������ ���� ��尡 �ǰ� �Ѵ�.
	ChangeRightSubTree1(pVRoot, *pRoot);

	// ���� ����� ������ ��� Ž��
	while (cNode != NULL && strcmp(GetData1(cNode), target) != 0)
	{
		pNode = cNode;

		if (strcmp(target, GetData1(cNode)) < 0)
			cNode = GetLeftSubTree1(cNode);
		else
			cNode = GetRightSubTree1(cNode);
	}

	if (cNode == NULL)    // ���� ����� �������� �ʴ´ٸ�,
		return NULL;

	dNode = cNode;    // ���� ����� dNode�� ����Ű�� �Ѵ�.

					  // ù ��° ���: ������ ��尡 �ܸ� ����� ���
	if (GetLeftSubTree1(dNode) == NULL && GetRightSubTree1(dNode) == NULL)
	{
		if (GetLeftSubTree1(pNode) == dNode)
			RemoveLeftSubTree1(pNode);
		else
			RemoveRightSubTree1(pNode);
	}

	// �� ��° ���: �ϳ��� �ڽ� ��带 ���� ���
	else if (GetLeftSubTree1(dNode) == NULL || GetRightSubTree1(dNode) == NULL)
	{
		WordNode * dcNode;    // delete node�� �ڽ� ���

		if (GetLeftSubTree1(dNode) != NULL)
			dcNode = GetLeftSubTree1(dNode);
		else
			dcNode = GetRightSubTree1(dNode);

		if (GetLeftSubTree1(pNode) == dNode)
			ChangeLeftSubTree1(pNode, dcNode);
		else
			ChangeRightSubTree1(pNode, dcNode);
	}

	// �� ��° ���: �� ���� �ڽ� ��带 ��� ���� ���
	else
	{
		WordNode * mNode = GetRightSubTree1(dNode);    // mininum node
		WordNode * mpNode = dNode;    // mininum node�� �θ� ���
		char delData[100];

		// ������ ��带 ��ü�� ��带 ã�´�.
		while (GetLeftSubTree1(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree1(mNode);
		}

		// ��ü�� ��忡 ����� ���� ������ ��忡 �����Ѵ�.
		strcpy(delData, GetData1(dNode));    // ���� �� ������ ���
		SetData1(dNode, GetData1(mNode));

		// ��ü�� ����� �θ� ���� �ڽ� ��带 �����Ѵ�.
		if (GetLeftSubTree1(mpNode) == mNode)
			ChangeLeftSubTree1(mpNode, GetRightSubTree1(mNode));
		else
			ChangeRightSubTree1(mpNode, GetRightSubTree1(mNode));

		dNode = mNode;
		SetData1(dNode, delData);    // ��� ������ ����
	}

	// ������ ��尡 ��Ʈ ����� ��쿡 ���� ó��
	if (GetRightSubTree1(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree1(pVRoot);

	free(pVRoot);

	*pRoot = Rebalance1(pRoot); 	// ��� ���� �� ���뷱��!
	return dNode;
}

void ShowIntData1(int data)
{
	printf("%d ", data);
}

void BSTShowAll1(WordNode * bst)
{
	InorderTraverse1(bst, ShowIntData1);
}


