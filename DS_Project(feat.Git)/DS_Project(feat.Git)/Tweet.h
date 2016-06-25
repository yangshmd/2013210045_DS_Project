#include "BinaryTree3.h"

// Enumeration about lines of each files.
enum { USER_TXT_ID_LINE, USER_TXT_DATE_LINE, USER_TXT_REALID_LINE, USER_TXT_BLANK_LINE };
enum { WORD_TXT_ID_LINE, WORD_TXT_DATE_LINE, WORD_TXT_WORD_LINE, WORD_TXT_BLANK_LINE };
enum { FRIEND_TXT_ME_LINE, FRIEND_TXT_FR_LINE, FRIEND_TXT_BLANK_LINE };

void ShowInterface();
void ReadDataFiles(int userNum, int friendNum, int tweetNum);
void ShowStatistics(BTreeNode* userRoot, WordNode* wordRoot, int tF, int tU, int tT, BTreeNode* arr[]);

void TopFiveWords(WordNode* arr1[], int wordNodeCount);
void TopFiveUsers(BTreeNode* arr[], int userNum);

void FindUsersWhoTweetedWord(WordNode* wordRoot, char* wordTemp, int flag);
void FindAllFriendsAboveUsers(WordNode* wordRoot, char* wordTemp, int flag);

int DeleteAllMentionsOfWord(WordNode* wordRoot, char* wordTemp);
int DeleteUsersWhoMentionedWord(BTreeNode* userRoot, WordNode* wordRoot, char* wordTemp);

void FindStronglyConnectedComponents(BTreeNode* userRoot);
void FindShortestPath(BTreeNode* userRoot, char* wordTemp);