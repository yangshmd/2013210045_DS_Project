#ifndef __BINARY_TREE3_H__
#define __BINARY_TREE3_H__

#define STR_LEN		300

#define TRUE	1
#define FALSE	0

#define ID_LENGTH		50
#define REAL_ID_LENGTH	100

#define WORD_LENGTH		300
#define ARR_SIZE		700

typedef char* BTData;

typedef struct _userNode
{
	char data[ID_LENGTH];	// data == id. (key)
	char read_ID[REAL_ID_LENGTH];

	int numOfTweets;
	int numOfFriends;

	struct _userNode* friendsInfo [ARR_SIZE];
	struct _userNode* left;
	struct _userNode* right;
} BTreeNode;

typedef struct _wordNode
{
	char data[WORD_LENGTH];	// data == word. (key)
	int numOfTweeted;
	BTreeNode* whoTweeted [ARR_SIZE];
	struct _wordNode* left;
	struct _wordNode* right;
} WordNode;


/////// UserNode(BTreeNode) ���� �Լ� //////

BTreeNode * MakeBTreeNode(void);
BTData GetData(BTreeNode * bt);
void SetData(BTreeNode * bt, BTData data);

BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);

typedef void VisitFuncPtr(BTData data);

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action);

// ���� �ڽ� ��� ����, ���ŵ� ����� �ּ� ���� ��ȯ�ȴ�.
BTreeNode * RemoveLeftSubTree(BTreeNode * bt);

// ������ �ڽ� ��� ����, ���ŵ� ����� �ּ� ���� ��ȯ�ȴ�.
BTreeNode * RemoveRightSubTree(BTreeNode * bt);

// �޸� �Ҹ��� �������� �ʰ� main�� ���� �ڽ� ��带 �����Ѵ�. 
void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub);

// �޸� �Ҹ��� �������� �ʰ� main�� ������ �ڽ� ��带 �����Ѵ�. 
void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub);

void InsertScreenID(BTreeNode* bt, BTData realID);




//////////WordNode ���� �Լ� ////////////

WordNode * MakeWordNode1(void);
BTData GetData1(WordNode * bt);
void SetData1(WordNode * bt, BTData data);

WordNode * GetLeftSubTree1(WordNode * bt);
WordNode * GetRightSubTree1(WordNode * bt);

void MakeLeftSubTree1(WordNode * main, WordNode * sub);
void MakeRightSubTree1(WordNode * main, WordNode * sub);

typedef void VisitFuncPtr1(BTData data);

void PreorderTraverse1(WordNode * bt, VisitFuncPtr1 action);
void InorderTraverse1(WordNode * bt, VisitFuncPtr1 action);
void PostorderTraverse1(WordNode * bt, VisitFuncPtr1 action);

// ���� �ڽ� ��� ����, ���ŵ� ����� �ּ� ���� ��ȯ�ȴ�.
WordNode * RemoveLeftSubTree1(WordNode * bt);

// ������ �ڽ� ��� ����, ���ŵ� ����� �ּ� ���� ��ȯ�ȴ�.
WordNode * RemoveRightSubTree1(WordNode * bt);

// �޸� �Ҹ��� �������� �ʰ� main�� ���� �ڽ� ��带 �����Ѵ�. 
void ChangeLeftSubTree1(WordNode * main, WordNode * sub);

// �޸� �Ҹ��� �������� �ʰ� main�� ������ �ڽ� ��带 �����Ѵ�. 
void ChangeRightSubTree1(WordNode * main, WordNode * sub);

#endif