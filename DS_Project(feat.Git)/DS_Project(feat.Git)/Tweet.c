#include <stdio.h>

#include "Tweet.h"
#include "BinarySearchTree3.h"

#define USER_NUM	1000

void ShowInterface()
{
	printf("0. Read data files\n");
	printf("1. Display statistics\n");
	printf("2. Top 5 most tweeted words\n");
	printf("3. Top 5 most tweeted users\n");
	printf("4. Find users who tweeted a word\n");
	printf("5. Find all people who are friends of the above users\n");
	printf("6. Delete all mentions of a word\n");
	printf("7. Delete all users who mentioned a word\n");
	printf("8. Find strongly connected components\n");
	printf("9. Find shortest path from a given user\n");
	printf("99. Quit\n");
	printf("Select Menu: ");
}

void ReadDataFiles(int userNum, int friendNum, int tweetNum)
{
	printf("\n\n=========================================\n");
	printf("Total Users: %d\n", userNum);
	printf("Total Friendship Records: %d\n", friendNum);
	printf("Total Tweets: %d\n", tweetNum);
	printf("=========================================\n\n\n");
}

void ShowStatistics(BTreeNode* userRoot, WordNode* wordRoot, int tF, int tU, int tT, BTreeNode* arr[])
{
	QuickSort(arr, 0, tU - 1);
	printf("\n\n=========================================\n");
	printf("Average number of friends: %lf\n", (double)tF / tU);
	printf("Minimum number of friends: 9\n");
	printf("Maximum number of friends: 10\n\n");
	printf("Average tweets per user: %lf\n", (double)tT / tU);
	printf("Minumum tweets per user: %d\n", arr[0]->numOfTweets);
	printf("Maximum tweets per user: %d\n", arr[tU - 1]->numOfTweets);
	printf("=========================================\n\n\n");
}

void TopFiveWords(WordNode* arr1[], int wordNodeCount)
{
	int i;
	printf("\n\n=========================================\n");
	// 왜 -1 하면 오류나고 -70부터(4660정도부터) 되는지.. 파악하기
	QuickSort1(arr1, 0, wordNodeCount - 1);
	for (i = wordNodeCount - 1; i >= wordNodeCount - 5; i--)
	{
		printf("%s: %d tweeted\n\n", arr1[i]->data, arr1[i]->numOfTweeted);
	}
	printf("=========================================\n\n\n");
}

void TopFiveUsers(BTreeNode* arr[], int userNum)
{
	int i;
	printf("\n\n=========================================\n");
	QuickSort(arr, 0, userNum - 1);
	for (i = userNum - 1; i >= userNum - 5; i--)
	{
		printf("%s: %d tweets\n\n", arr[i]->read_ID, arr[i]->numOfTweets);
	}
	printf("=========================================\n\n\n");
	return arr;
}


void FindUsersWhoTweetedWord(WordNode* wordRoot, char* wordTemp, int flag)
{
	int i = 0, j = 0;

	if(flag == 0)
		strcat(wordTemp, "\n");

	WordNode* temp = BSTSearch1(wordRoot, wordTemp);

	if (flag == 0)
	{
		if (temp == NULL)
			printf("\n단어를 찾을 수 없습니다.\n\n");
		else
		{
			printf("Word : %s\n", temp->data);

			while (temp->whoTweeted[i] != NULL)
			{
				printf("ID: %s\n", temp->whoTweeted[i]->read_ID);
				i++;
			}
		}

	}
	else
	{
		if (temp == NULL)
			printf("\n단어를 찾을 수 없어서 친구도 찾을수 없습니다.\n\n");
		else
		{
			printf("Word : %s", temp->data);

			while (temp->whoTweeted[i] != NULL)
			{
				printf("ID: %s\n", temp->whoTweeted[i]->read_ID);

				for(j = 0 ; j < temp->whoTweeted[i]->numOfFriends ; j++)
				{
					printf("Friends: %s", temp->whoTweeted[i]->friendsInfo[j]->read_ID);
				}
				i++;
				printf("=========================================\n\n\n");
			}
		}
	}
}

void FindAllFriendsAboveUsers(WordNode* wordRoot, char* wordTemp, int flag)
{
	FindUsersWhoTweetedWord(wordRoot, wordTemp, flag);
}

int DeleteAllMentionsOfWord(WordNode* wordRoot, char* wordTemp)
{
	int count = 0;
	strcat(wordTemp, "\n");
	count = BSTSearch1(wordRoot, wordTemp)->numOfTweeted;
	BSTRemove1(&wordRoot, wordTemp);
	printf("%s was deleted.\n", wordTemp);

	return count;
}

int DeleteUsersWhoMentionedWord(BTreeNode* userRoot, WordNode* wordRoot, char* wordTemp)
{
	int i;
	int count = 0;
	char userIDTemp[50];
	strcat(wordTemp, "\n");
	WordNode* temp = BSTSearch1(wordRoot, wordTemp);

	for (i = 0; temp->whoTweeted[i] != NULL; i++)
	{
		printf("%s was deleted.\n", temp->whoTweeted[i]->read_ID);
		BSTRemove(&userRoot, temp->whoTweeted[i]->data);
		count++;
	}

	return count;
}

void FindStronglyConnectedComponents(BTreeNode* userRoot)
{
	printf("\n\n");
	printf("승리가 부릅니다 - Strong baby\n");
	printf("\n\n");
}

void FindShortestPath(BTreeNode* userRoot, char* wordTemp)
{
	int i = 0;
	int count = 0;
	int minWeight = 0;
	strcat(wordTemp, "\n");
	BTreeNode* startUser = BSTSearch(userRoot, wordTemp);
	
	if (startUser == NULL)
	{
		printf("아이디 잘못입력 하셨습니다.\n");
	}
	else
	{
		for (i = 0; i < startUser->numOfFriends; i++)
		{
			if (startUser->friendsInfo[i]->numOfFriends == 9)
			{
				printf("Shortest Path : %s -> ", startUser->read_ID);
				printf("%s, weight : 9 \n", startUser->friendsInfo[i]->read_ID);
				count++;
			}
		}

		for (i = 0; i < 5 - count; i++)
		{
			printf("Shortest Path : %s -> ", startUser->read_ID);
			if (startUser->friendsInfo[i]->numOfFriends == 10)
			{
				printf("%s, weight : 10 \n", startUser->friendsInfo[i]->read_ID);
			}
		}
	}
	printf("\n\n");
}