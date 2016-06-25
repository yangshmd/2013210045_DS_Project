#ifndef __BINARY_SEARCH_TREE3_H__
#define __BINARY_SEARCH_TREE3_H__

#include "BinaryTree3.h"

typedef BTData	BSTData;

//////////User����////////////
// ���� Ž�� Ʈ���� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode ** pRoot);

// ��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode * bst);

// ���� Ž�� Ʈ���� ������� ������ ����(����� �������� ����)
BTreeNode* BSTInsert(BTreeNode ** pRoot, BSTData data);

// ���� Ž�� Ʈ���� ������� ������ Ž��
BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);

// Ʈ������ ��带 �����ϰ� ���ŵ� ����� �ּ� ���� ��ȯ�Ѵ�. 
BTreeNode * BSTRemove(BTreeNode ** pRoot, BSTData target);

// ���� Ž�� Ʈ���� ����� ��� ����� �����͸� ����Ѵ�.
void BSTShowAll(BTreeNode * bst);








/////////////Word����//////////////
void BSTMakeAndInit1(WordNode ** pRoot);

// ��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData1(WordNode * bst);

// ���� Ž�� Ʈ���� ������� ������ ����(����� �������� ����)
WordNode* BSTInsert1(WordNode ** pRoot, BSTData data);

// ���� Ž�� Ʈ���� ������� ������ Ž��
WordNode * BSTSearch1(WordNode * bst, BSTData target);

// Ʈ������ ��带 �����ϰ� ���ŵ� ����� �ּ� ���� ��ȯ�Ѵ�. 
WordNode * BSTRemove1(WordNode ** pRoot, BSTData target);

// ���� Ž�� Ʈ���� ����� ��� ����� �����͸� ����Ѵ�.
void BSTShowAll1(WordNode * bst);

#endif