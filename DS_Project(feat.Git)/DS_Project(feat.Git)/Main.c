#include <stdio.h>

#define TRUE	1
#define FALSE	0

void PrintInterface();

void PrintInterface()
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

int main(void)
{
	int selectMenu;

	FILE* fp_word = fopen("word.txt", "rt");
	FILE* fp_user = fopen("user.txt", "rt");
	FILE* fp_friend = fopen("friend.txt", "rt");

	while (TRUE)
	{
		PrintInterface();
		scanf("%d", &selectMenu);
		gets();

		switch (selectMenu)
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		default:
			break;
		}
	}

}