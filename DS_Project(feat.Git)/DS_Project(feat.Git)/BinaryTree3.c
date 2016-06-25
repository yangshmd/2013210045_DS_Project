#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree3.h"
#include "Tweet.h"

///////////BTreeNode(User 관련)//////////
BTreeNode * MakeBTreeNode(void)
{
	BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));

	nd->left = NULL;
	nd->right = NULL;

	nd->numOfTweets = 0;
	nd->numOfFriends = 0;

	return nd;
}

BTData GetData(BTreeNode * bt)
{
	return bt->data;
}

void SetData(BTreeNode * bt, BTData data)
{
	strncpy(bt->data, data, sizeof(bt->data));
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
	return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	action(bt->numOfFriends);
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}

BTreeNode * RemoveLeftSubTree(BTreeNode * bt)
{
	BTreeNode * delNode;

	if (bt != NULL) {
		delNode = bt->left;
		bt->left = NULL;
	}
	return delNode;
}

BTreeNode * RemoveRightSubTree(BTreeNode * bt)
{
	BTreeNode * delNode;

	if (bt != NULL) {
		delNode = bt->right;
		bt->right = NULL;
	}
	return delNode;
}

void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
	main->left = sub;
}

void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
	main->right = sub;
}

// ID입력
void InsertScreenID(BTreeNode* bt, BTData realID)
{
	strncpy(bt->read_ID, realID, sizeof(bt->read_ID));
}

















//////////////Word관련//////////
WordNode * MakeWordNode1(void)
{
	int i;
	WordNode * nd = (WordNode*)malloc(sizeof(WordNode));
	
	nd->left = NULL;
	nd->right = NULL;

	nd->numOfTweeted = 1;
	
	for (i = 0; i < ARR_SIZE; i++)
		nd->whoTweeted[i] = NULL;

	return nd;
}

BTData GetData1(WordNode * bt)
{
	return bt->data;
}

void SetData1(WordNode * bt, BTData data)
{
	strncpy(bt->data, data, sizeof(bt->data));
}

WordNode * GetLeftSubTree1(WordNode * bt)
{
	return bt->left;
}

WordNode * GetRightSubTree1(WordNode * bt)
{
	return bt->right;
}

void MakeLeftSubTree1(WordNode * main, WordNode * sub)
{
	if (main->left != NULL)
		free(main->left);

	main->left = sub;
}

void MakeRightSubTree1(WordNode * main, WordNode * sub)
{
	if (main->right != NULL)
		free(main->right);

	main->right = sub;
}

void PreorderTraverse1(WordNode * bt, VisitFuncPtr1 action)
{
	if (bt == NULL)
		return;

	action(bt->data);
	PreorderTraverse1(bt->left, action);
	PreorderTraverse1(bt->right, action);
}

void InorderTraverse1(WordNode * bt, VisitFuncPtr1 action)
{
	if (bt == NULL)
		return;

	InorderTraverse1(bt->left, action);
	action(bt->numOfTweeted);
	InorderTraverse1(bt->right, action);
}

void PostorderTraverse1(WordNode * bt, VisitFuncPtr1 action)
{
	if (bt == NULL)
		return;

	PostorderTraverse1(bt->left, action);
	PostorderTraverse1(bt->right, action);
	action(bt->data);
}

WordNode * RemoveLeftSubTree1(WordNode * bt)
{
	WordNode * delNode;

	if (bt != NULL) {
		delNode = bt->left;
		bt->left = NULL;
	}
	return delNode;
}

WordNode * RemoveRightSubTree1(WordNode * bt)
{
	WordNode * delNode;

	if (bt != NULL) {
		delNode = bt->right;
		bt->right = NULL;
	}
	return delNode;
}

void ChangeLeftSubTree1(WordNode * main, WordNode * sub)
{
	main->left = sub;
}

void ChangeRightSubTree1(WordNode * main, WordNode * sub)
{
	main->right = sub;
}
