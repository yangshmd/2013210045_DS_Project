#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree3.h"
#include "BinarySearchTree3.h"
#include "AVLRebalance.h"


/////////////User 관련/////////////////
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

								 // 새로운 노드가 추가될 위치를 찾는다.
	while (cNode != NULL)
	{
		if (strcmp(data, GetData(cNode)) == 0)
			return NULL;    // 키의 중복을 허용하지 않음

		pNode = cNode;

		if (strcmp(GetData(cNode), data) > 0)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	// pNode의 서브 노드에 추가할 새 노드의 생성
	nNode = MakeBTreeNode();    // 새 노드의 생성
	SetData(nNode, data);    // 새 노드에 데이터 저장

							 // pNode의 서브 노드에 새 노드를 추가
	if (pNode != NULL)    // 새 노드가 루트 노드가 아니라면,
	{
		if (strcmp(data, GetData(pNode)) < 0)
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else    // 새 노드가 루트 노드라면,
	{
		*pRoot = nNode;
	}

	*pRoot = Rebalance(pRoot);	// 노드 추가 후 리밸런싱

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
	// 삭제 대상이 루트 노드인 경우를 별도로 고려해야 한다.

	BTreeNode * pVRoot = MakeBTreeNode();    // 가상 루트 노드;

	BTreeNode * pNode = pVRoot;    // parent node
	BTreeNode * cNode = *pRoot;    // current node
	BTreeNode * dNode;    // delete node

						  // 루트 노드를 pVRoot가 가리키는 노드의 오른쪽 서브 노드가 되게 한다.
	ChangeRightSubTree(pVRoot, *pRoot);

	// 삭제 대상을 저장한 노드 탐색
	while (cNode != NULL && strcmp(GetData(cNode), target) != 0)
	{
		pNode = cNode;

		if (strcmp(target, GetData(cNode)) < 0)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	if (cNode == NULL)    // 삭제 대상이 존재하지 않는다면,
		return NULL;

	dNode = cNode;    // 삭제 대상을 dNode가 가리키게 한다.

					  // 첫 번째 경우: 삭제할 노드가 단말 노드인 경우
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
	{
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}

	// 두 번째 경우: 하나의 자식 노드를 갖는 경우
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
	{
		BTreeNode * dcNode;    // delete node의 자식 노드

		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	// 세 번째 경우: 두 개의 자식 노드를 모두 갖는 경우
	else
	{
		BTreeNode * mNode = GetRightSubTree(dNode);    // mininum node
		BTreeNode * mpNode = dNode;    // mininum node의 부모 노드
		char delData[100];

		// 삭제할 노드를 대체할 노드를 찾는다.
		while (GetLeftSubTree(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		// 대체할 노드에 저장된 값을 삭제할 노드에 대입한다.
		strcpy(delData, GetData(dNode));    // 대입 전 데이터 백업
		SetData(dNode, GetData(mNode));

		// 대체할 노드의 부모 노드와 자식 노드를 연결한다.
		if (GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData);    // 백업 데이터 복원
	}

	// 삭제된 노드가 루트 노드인 경우에 대한 처리
	if (GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);

	free(pVRoot);

	*pRoot = Rebalance(pRoot); 	// 노드 제거 후 리밸런싱!
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









//////////////Word 관련//////////////

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

								 // 새로운 노드가 추가될 위치를 찾는다.
	while (cNode != NULL)
	{
		if (strcmp(data, GetData1(cNode)) == 0)
			return NULL;    // 키의 중복을 허용하지 않음

		pNode = cNode;

		if (strcmp(GetData1(cNode), data) > 0)
			cNode = GetLeftSubTree1(cNode);
		else
			cNode = GetRightSubTree1(cNode);
	}

	// pNode의 서브 노드에 추가할 새 노드의 생성
	nNode = MakeWordNode1();    // 새 노드의 생성
	SetData1(nNode, data);    // 새 노드에 데이터 저장

							 // pNode의 서브 노드에 새 노드를 추가
	if (pNode != NULL)    // 새 노드가 루트 노드가 아니라면,
	{
		if (strcmp(data, GetData1(pNode)) < 0)
			MakeLeftSubTree1(pNode, nNode);
		else
			MakeRightSubTree1(pNode, nNode);
	}
	else    // 새 노드가 루트 노드라면,
	{
		*pRoot = nNode;
	}

	*pRoot = Rebalance1(pRoot);	// 노드 추가 후 리밸런싱

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
	// 삭제 대상이 루트 노드인 경우를 별도로 고려해야 한다.

	WordNode * pVRoot = MakeWordNode1();    // 가상 루트 노드;

	WordNode * pNode = pVRoot;    // parent node
	WordNode * cNode = *pRoot;    // current node
	WordNode * dNode;    // delete node

						  // 루트 노드를 pVRoot가 가리키는 노드의 오른쪽 서브 노드가 되게 한다.
	ChangeRightSubTree1(pVRoot, *pRoot);

	// 삭제 대상을 저장한 노드 탐색
	while (cNode != NULL && strcmp(GetData1(cNode), target) != 0)
	{
		pNode = cNode;

		if (strcmp(target, GetData1(cNode)) < 0)
			cNode = GetLeftSubTree1(cNode);
		else
			cNode = GetRightSubTree1(cNode);
	}

	if (cNode == NULL)    // 삭제 대상이 존재하지 않는다면,
		return NULL;

	dNode = cNode;    // 삭제 대상을 dNode가 가리키게 한다.

					  // 첫 번째 경우: 삭제할 노드가 단말 노드인 경우
	if (GetLeftSubTree1(dNode) == NULL && GetRightSubTree1(dNode) == NULL)
	{
		if (GetLeftSubTree1(pNode) == dNode)
			RemoveLeftSubTree1(pNode);
		else
			RemoveRightSubTree1(pNode);
	}

	// 두 번째 경우: 하나의 자식 노드를 갖는 경우
	else if (GetLeftSubTree1(dNode) == NULL || GetRightSubTree1(dNode) == NULL)
	{
		WordNode * dcNode;    // delete node의 자식 노드

		if (GetLeftSubTree1(dNode) != NULL)
			dcNode = GetLeftSubTree1(dNode);
		else
			dcNode = GetRightSubTree1(dNode);

		if (GetLeftSubTree1(pNode) == dNode)
			ChangeLeftSubTree1(pNode, dcNode);
		else
			ChangeRightSubTree1(pNode, dcNode);
	}

	// 세 번째 경우: 두 개의 자식 노드를 모두 갖는 경우
	else
	{
		WordNode * mNode = GetRightSubTree1(dNode);    // mininum node
		WordNode * mpNode = dNode;    // mininum node의 부모 노드
		char delData[100];

		// 삭제할 노드를 대체할 노드를 찾는다.
		while (GetLeftSubTree1(mNode) != NULL)
		{
			mpNode = mNode;
			mNode = GetLeftSubTree1(mNode);
		}

		// 대체할 노드에 저장된 값을 삭제할 노드에 대입한다.
		strcpy(delData, GetData1(dNode));    // 대입 전 데이터 백업
		SetData1(dNode, GetData1(mNode));

		// 대체할 노드의 부모 노드와 자식 노드를 연결한다.
		if (GetLeftSubTree1(mpNode) == mNode)
			ChangeLeftSubTree1(mpNode, GetRightSubTree1(mNode));
		else
			ChangeRightSubTree1(mpNode, GetRightSubTree1(mNode));

		dNode = mNode;
		SetData1(dNode, delData);    // 백업 데이터 복원
	}

	// 삭제된 노드가 루트 노드인 경우에 대한 처리
	if (GetRightSubTree1(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree1(pVRoot);

	free(pVRoot);

	*pRoot = Rebalance1(pRoot); 	// 노드 제거 후 리밸런싱!
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


