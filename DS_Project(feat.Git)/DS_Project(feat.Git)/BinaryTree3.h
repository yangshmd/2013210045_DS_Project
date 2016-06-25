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


/////// UserNode(BTreeNode) 관련 함수 //////

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

// 왼쪽 자식 노드 제거, 제거된 노드의 주소 값이 반환된다.
BTreeNode * RemoveLeftSubTree(BTreeNode * bt);

// 오른쪽 자식 노드 제거, 제거된 노드의 주소 값이 반환된다.
BTreeNode * RemoveRightSubTree(BTreeNode * bt);

// 메모리 소멸을 수반하지 않고 main의 왼쪽 자식 노드를 변경한다. 
void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub);

// 메모리 소멸을 수반하지 않고 main의 오른쪽 자식 노드를 변경한다. 
void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub);

void InsertScreenID(BTreeNode* bt, BTData realID);




//////////WordNode 관련 함수 ////////////

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

// 왼쪽 자식 노드 제거, 제거된 노드의 주소 값이 반환된다.
WordNode * RemoveLeftSubTree1(WordNode * bt);

// 오른쪽 자식 노드 제거, 제거된 노드의 주소 값이 반환된다.
WordNode * RemoveRightSubTree1(WordNode * bt);

// 메모리 소멸을 수반하지 않고 main의 왼쪽 자식 노드를 변경한다. 
void ChangeLeftSubTree1(WordNode * main, WordNode * sub);

// 메모리 소멸을 수반하지 않고 main의 오른쪽 자식 노드를 변경한다. 
void ChangeRightSubTree1(WordNode * main, WordNode * sub);

#endif