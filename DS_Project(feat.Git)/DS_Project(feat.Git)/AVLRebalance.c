#include <stdio.h>
#include "BinaryTree3.h"

//////////////////User ����///////////////

// LL ȸ��
BTreeNode * RotateLL(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);
	return cNode;
}

// RR ȸ��
BTreeNode * RotateRR(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);
	return cNode;
}

// RL ȸ��
BTreeNode * RotateRL(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode, RotateLL(cNode));   // �κ��� LL ȸ��
	return RotateRR(pNode);     // RR ȸ��
}

// LR ȸ��
BTreeNode * RotateLR(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);
	
	ChangeLeftSubTree(pNode, RotateRR(cNode));   // �κ��� RR ȸ��
	return RotateLL(pNode);     // LL ȸ��
}

// Ʈ���� ���̸� ����Ͽ� ��ȯ
int GetHeight(BTreeNode * bst) 
{
	int leftH;		// left height
	int rightH;		// right height

	if(bst == NULL)
		return 0;

	// ���� ���� Ʈ�� ���� ���
	leftH = GetHeight(GetLeftSubTree(bst));

	// ������ ���� Ʈ�� ���� ���
	rightH = GetHeight(GetRightSubTree(bst));

	// ū ���� ���̸� ��ȯ�Ѵ�.
	if(leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

// �� ���� Ʈ���� ������ ���� ��ȯ
int GetHeightDiff(BTreeNode * bst)
{
	int lsh;    // left sub tree height
	int rsh;    // right sub tree height

	if(bst == NULL)
		return 0;

	lsh = GetHeight(GetLeftSubTree(bst));
	rsh = GetHeight(GetRightSubTree(bst));

	return lsh - rsh;
}

// Ʈ���� ������ ��´�.
BTreeNode * Rebalance(BTreeNode ** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot);

	if(hDiff > 1)     // ���� ���� Ʈ�� �������� ���̰� 2 �̻� ũ�ٸ�
	{
		if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
			*pRoot = RotateLL(*pRoot);
		else
			*pRoot = RotateLR(*pRoot);
	}
	
	if(hDiff < -1)     // ������ ���� Ʈ�� �������� 2 �̻� ũ�ٸ�
	{
		if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot);
		else
			*pRoot = RotateRL(*pRoot);
	}
	
	return *pRoot;
}

//////////////Word ����///////////////

// LL ȸ��
WordNode * RotateLL1(WordNode * bst)
{
	WordNode * pNode;
	WordNode * cNode;

	pNode = bst;
	cNode = GetLeftSubTree1(pNode);

	ChangeLeftSubTree1(pNode, GetRightSubTree1(cNode));
	ChangeRightSubTree1(cNode, pNode);
	return cNode;
}

// RR ȸ��
WordNode * RotateRR1(WordNode * bst)
{
	WordNode * pNode;
	WordNode * cNode;

	pNode = bst;
	cNode = GetRightSubTree1(pNode);

	ChangeRightSubTree1(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree1(cNode, pNode);
	return cNode;
}

// RL ȸ��
WordNode * RotateRL1(WordNode * bst)
{
	WordNode * pNode;
	WordNode * cNode;

	pNode = bst;
	cNode = GetRightSubTree1(pNode);

	ChangeRightSubTree1(pNode, RotateLL1(cNode));   // �κ��� LL ȸ��
	return RotateRR1(pNode);     // RR ȸ��
}

// LR ȸ��
WordNode * RotateLR1(WordNode * bst)
{
	WordNode * pNode;
	WordNode * cNode;

	pNode = bst;
	cNode = GetLeftSubTree1(pNode);

	ChangeLeftSubTree1(pNode, RotateRR1(cNode));   // �κ��� RR ȸ��
	return RotateLL1(pNode);     // LL ȸ��
}

// Ʈ���� ���̸� ����Ͽ� ��ȯ
int GetHeight1(WordNode * bst)
{
	int leftH;		// left height
	int rightH;		// right height

	if (bst == NULL)
		return 0;

	// ���� ���� Ʈ�� ���� ���
	leftH = GetHeight1(GetLeftSubTree1(bst));

	// ������ ���� Ʈ�� ���� ���
	rightH = GetHeight1(GetRightSubTree1(bst));

	// ū ���� ���̸� ��ȯ�Ѵ�.
	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

// �� ���� Ʈ���� ������ ���� ��ȯ
int GetHeightDiff1(WordNode * bst)
{
	int lsh;    // left sub tree height
	int rsh;    // right sub tree height

	if (bst == NULL)
		return 0;

	lsh = GetHeight1(GetLeftSubTree1(bst));
	rsh = GetHeight1(GetRightSubTree1(bst));

	return lsh - rsh;
}

// Ʈ���� ������ ��´�.
WordNode * Rebalance1(WordNode ** pRoot)
{
	int hDiff = GetHeightDiff1(*pRoot);

	if (hDiff > 1)     // ���� ���� Ʈ�� �������� ���̰� 2 �̻� ũ�ٸ�
	{
		if (GetHeightDiff1(GetLeftSubTree1(*pRoot)) > 0)
			*pRoot = RotateLL1(*pRoot);
		else
			*pRoot = RotateLR1(*pRoot);
	}

	if (hDiff < -1)     // ������ ���� Ʈ�� �������� 2 �̻� ũ�ٸ�
	{
		if (GetHeightDiff1(GetRightSubTree1(*pRoot)) < 0)
			*pRoot = RotateRR1(*pRoot);
		else
			*pRoot = RotateRL1(*pRoot);
	}

	return *pRoot;
}