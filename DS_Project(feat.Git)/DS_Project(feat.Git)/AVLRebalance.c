#include <stdio.h>
#include "BinaryTree3.h"

//////////////////User 관련///////////////

// LL 회전
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

// RR 회전
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

// RL 회전
BTreeNode * RotateRL(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode, RotateLL(cNode));   // 부분적 LL 회전
	return RotateRR(pNode);     // RR 회전
}

// LR 회전
BTreeNode * RotateLR(BTreeNode * bst)
{
	BTreeNode * pNode;
	BTreeNode * cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);
	
	ChangeLeftSubTree(pNode, RotateRR(cNode));   // 부분적 RR 회전
	return RotateLL(pNode);     // LL 회전
}

// 트리의 높이를 계산하여 반환
int GetHeight(BTreeNode * bst) 
{
	int leftH;		// left height
	int rightH;		// right height

	if(bst == NULL)
		return 0;

	// 왼쪽 서브 트리 높이 계산
	leftH = GetHeight(GetLeftSubTree(bst));

	// 오른쪽 서브 트리 높이 계산
	rightH = GetHeight(GetRightSubTree(bst));

	// 큰 값의 높이를 반환한다.
	if(leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

// 두 서브 트리의 높이의 차를 반환
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

// 트리의 균형을 잡는다.
BTreeNode * Rebalance(BTreeNode ** pRoot)
{
	int hDiff = GetHeightDiff(*pRoot);

	if(hDiff > 1)     // 왼쪽 서브 트리 방향으로 높이가 2 이상 크다면
	{
		if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
			*pRoot = RotateLL(*pRoot);
		else
			*pRoot = RotateLR(*pRoot);
	}
	
	if(hDiff < -1)     // 오른쪽 서브 트리 방향으로 2 이상 크다면
	{
		if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot);
		else
			*pRoot = RotateRL(*pRoot);
	}
	
	return *pRoot;
}

//////////////Word 관련///////////////

// LL 회전
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

// RR 회전
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

// RL 회전
WordNode * RotateRL1(WordNode * bst)
{
	WordNode * pNode;
	WordNode * cNode;

	pNode = bst;
	cNode = GetRightSubTree1(pNode);

	ChangeRightSubTree1(pNode, RotateLL1(cNode));   // 부분적 LL 회전
	return RotateRR1(pNode);     // RR 회전
}

// LR 회전
WordNode * RotateLR1(WordNode * bst)
{
	WordNode * pNode;
	WordNode * cNode;

	pNode = bst;
	cNode = GetLeftSubTree1(pNode);

	ChangeLeftSubTree1(pNode, RotateRR1(cNode));   // 부분적 RR 회전
	return RotateLL1(pNode);     // LL 회전
}

// 트리의 높이를 계산하여 반환
int GetHeight1(WordNode * bst)
{
	int leftH;		// left height
	int rightH;		// right height

	if (bst == NULL)
		return 0;

	// 왼쪽 서브 트리 높이 계산
	leftH = GetHeight1(GetLeftSubTree1(bst));

	// 오른쪽 서브 트리 높이 계산
	rightH = GetHeight1(GetRightSubTree1(bst));

	// 큰 값의 높이를 반환한다.
	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

// 두 서브 트리의 높이의 차를 반환
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

// 트리의 균형을 잡는다.
WordNode * Rebalance1(WordNode ** pRoot)
{
	int hDiff = GetHeightDiff1(*pRoot);

	if (hDiff > 1)     // 왼쪽 서브 트리 방향으로 높이가 2 이상 크다면
	{
		if (GetHeightDiff1(GetLeftSubTree1(*pRoot)) > 0)
			*pRoot = RotateLL1(*pRoot);
		else
			*pRoot = RotateLR1(*pRoot);
	}

	if (hDiff < -1)     // 오른쪽 서브 트리 방향으로 2 이상 크다면
	{
		if (GetHeightDiff1(GetRightSubTree1(*pRoot)) < 0)
			*pRoot = RotateRR1(*pRoot);
		else
			*pRoot = RotateRL1(*pRoot);
	}

	return *pRoot;
}