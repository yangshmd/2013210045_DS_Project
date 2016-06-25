#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "Tweet.h"
#include "AVLRebalance.h"
#include "BinarySearchTree3.h"
#include "BinaryTree3.h"

#define BUF_SIZE	1000
#define WORD_SIZE	5000

#define JUST		0
#define ABOVE		1

int main(void)
{
	static int totalUsers = 0;
	static int totalTweets = 0;
	static int totalFriendship = 0;
	int wordNodeCount = 0;

	int i = 0, j = 1;
	int selectMenu;
	int curLine = 0;

	char temp[STR_LEN];
	char ID_temp[STR_LEN];

	

	FILE* fp_word = fopen("word.txt", "rt");
	FILE* fp_user = fopen("user.txt", "rt");
	FILE* fp_friend = fopen("friend.txt", "rt");

	BTreeNode* userRoot;
	WordNode* wordRoot;
	BSTMakeAndInit(&userRoot);
	BSTMakeAndInit1(&wordRoot);

	/* Read "user.txt" */
	BTreeNode* newNode;
	// BTreeNode* array for Top 5 most tweets word.
	BTreeNode** arr = (BTreeNode*)malloc(sizeof(BTreeNode*) * BUF_SIZE);
	while (fgets(temp, sizeof(temp), fp_user) != NULL)
	{
		if (curLine % 4 == USER_TXT_ID_LINE)
		{
			newNode = BSTInsert(&userRoot, temp);
			totalUsers++;
			arr[i++] = newNode;
		}
		else if (curLine % 4 == USER_TXT_REALID_LINE)
		{
			InsertScreenID(newNode, temp);
		}
		curLine++;
	}

	/* Read "friend.txt" */
	BTreeNode* newNode1;
	curLine = 0;
	while (fgets(temp, sizeof(temp), fp_friend) != NULL)
	{
		if (curLine % 3 == FRIEND_TXT_ME_LINE)
		{
			newNode1 = BSTSearch(userRoot, temp);
			totalFriendship++;
		}
		else if (curLine % 3 == FRIEND_TXT_FR_LINE)
		{
			newNode1->friendsInfo[newNode1->numOfFriends] = BSTSearch(userRoot, temp);
			newNode1->numOfFriends += 1;
			
		}
		curLine++;
	}

	/* Read "word.txt" */
	i = 0;
	static BTreeNode* tempNode;		// User 정보 임시저장
	WordNode* tempNode1;		// Word 정보 임시저장.
	WordNode* newnewNode;		// Word 정보 임시저장
	curLine = 0;
	WordNode** arr1 = (WordNode*)malloc(sizeof(WordNode*) * WORD_SIZE);

	while (fgets(temp, sizeof(temp), fp_word) != NULL)
	{
		if (curLine % 4 == WORD_TXT_ID_LINE)
		{
			tempNode = BSTSearch(userRoot, temp);
			tempNode->numOfTweets += 1;
		}
		else if (curLine % 4 == WORD_TXT_WORD_LINE)		
		{
			newnewNode = BSTInsert1(&wordRoot, temp);	// Insert 하고, newnewNode에 word형 노드 임시저장.
			
			if (newnewNode == NULL)	// 이미 나온 단어인경우
			{
				tempNode1 = BSTSearch1(wordRoot, temp);

				tempNode1->numOfTweeted += 1;
				tempNode1->whoTweeted[tempNode1->numOfTweeted - 1] = tempNode;
			}
			else			// 처음 나온 단어인경우
			{
				newnewNode->whoTweeted[0] = tempNode;
				arr1[i++] = newnewNode;
				wordNodeCount++;
			}
			totalTweets++;
		}
		curLine++;
	}

	/*tempNode1 = BSTSearch1(wordRoot, "열심히\n");
	printf("%s", tempNode1->whoTweeted[0]->read_ID);*/
		
	// data에 엔터까지 저장되는구나

	//tempNode1 = BSTSearch1(wordRoot, "열심히\0");
	
	/*BTreeNode* ttttt;
	ttttt = BSTSearch(userRoot, "108603824");
	if (ttttt == NULL)
		printf("XX\n");
	else
		printf("numOfTweets: %d\n", ttttt->numOfTweets);*/
	/*char wordTemp[500] = "도서관을";
	BTreeNode* searchUserTemp;
	WordNode* searchWordTemp;

	searchWordTemp = BSTSearc*h1(wordRoot, wordTemp);
//	printf("%s\n", searchWordTemp->data);

	//BSTShowAll(userRoot);
	/*searchUserTemp = BSTSearch(userRoot, "108902649");
	if (searchUserTemp == NULL)
		printf("can't find\n");
	else*/
		//printf("%s\n", userRoot->read_ID);

//	printf("%d\n", wordNodeCount);
	//printf("%d\n", wordNodeCount);
	//printf("%d\n", arr1[4730]->numOfTweeted);
	//BSTShowAll1(wordRoot);
	//BSTShowAll(userRoot);
	
	//for (i = 0; i < wordNodeCount; i++)
	//{
	//	printf("%d ", arr1[i]->numOfTweeted);
	//}

	//TopFiveWords(arr1, wordNodeCount);

	//ReadDataFiles(totalUsers, totalFriendship, totalTweets);

	//ShowStatistics(userRoot, wordRoot);

//	TopFiveUsers(arr, totalUsers);
	//FindUsersWhoTweetedWord(wordRoot, "열심히");

	//printf("%s\n", wordRoot->whoTweeted[0]->read_ID);
	
	
	/* Select Menu */
	char wordTemp[500];
	while (TRUE)
	{
		ShowInterface();
		scanf("%d", &selectMenu);
		getchar();						// 버퍼 비우기

		switch (selectMenu)
		{
		case 0:
			ReadDataFiles(totalUsers, totalFriendship, totalTweets);
			break;
		case 1:
			ShowStatistics(userRoot, wordRoot, totalFriendship, totalUsers, totalTweets, arr);
			break;
		case 2:
			TopFiveWords(arr1, wordNodeCount);
			break;
		case 3:
			TopFiveUsers(arr, totalUsers);
			break;
		case 4:
			printf("\n* Input Word: ");
			gets(wordTemp);
			FindUsersWhoTweetedWord(wordRoot, wordTemp, JUST);
			break;
		case 5:
			FindAllFriendsAboveUsers(wordRoot, wordTemp, ABOVE);
			break;
		case 6:
			printf("\n* Input Word: ");
			gets(wordTemp);
			totalTweets -= DeleteAllMentionsOfWord(wordRoot, wordTemp);
			break;
		case 7:
			printf("\n* Input Word: ");
			gets(wordTemp);
			totalUsers -= DeleteUsersWhoMentionedWord(userRoot, wordRoot, wordTemp);
			break;
		case 8:

			break;
		case 9:
			printf("\n* Input Given User: ");
			gets(wordTemp);
			FindShortestPath(userRoot, wordTemp);
			break;
		default:
			return 0;
		}
	}	


	fclose(fp_word);
	fclose(fp_friend);
	fclose(fp_user);

	return 0;
}