#include <stdio.h>
#include "BinaryTree3.h"


//////////////User Tweet횟수 위한 QuickSort////
void Swap(BTreeNode* arr[], int idx1, int idx2)
{
	BTreeNode* temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}


int Partition(BTreeNode* arr[], int left, int right)
{
	int pivot = arr[left]->numOfTweets;    // 피벗의 위치는 가장 왼쪽! 
	int low = left + 1;
	int high = right;

	while (low <= high)    // 교차되지 않을 때까지 반복
	{
		while (pivot >= arr[low]->numOfTweets && low <= right)
			low++;

		while (pivot <= arr[high]->numOfTweets && high >= (left + 1))
			high--;

		if (low <= high)    // 교차되지 않은 상태라면 Swap 실행
			Swap(arr, low, high);    // low와 high가 가리키는 대상 교환
	}

	Swap(arr, left, high);    // 피벗과 high가 가리키는 대상 교환
	return high;    // 옮겨진 피벗의 위치 정보 반환
}

void QuickSort(BTreeNode* arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);    // 둘로 나눠서 
		QuickSort(arr, left, pivot - 1);    // 왼쪽 영역을 정렬
		QuickSort(arr, pivot + 1, right);    // 오른쪽 영역을 정렬
	}
}


//////////// Word 개수 위한 QuickSort ////////
void QuickSort1(WordNode* arr1[], int left, int right) 
{
	int i = left, j = right;
	WordNode* tmp;
	int pivot = arr1[(left + right) / 2]->numOfTweeted;

	/* partition */
	while (i <= j) {
		while (arr1[i]->numOfTweeted < pivot)
			i++;
		while (arr1[j]->numOfTweeted > pivot)
			j--;
		if (i <= j) 
		{
			tmp = arr1[i];
			arr1[i] = arr1[j];
			arr1[j] = tmp;
			i++;
			j--;
		}
	}

	/* recursion */
	if (left < j)
		QuickSort1(arr1, left, j);
	if (i < right)
		QuickSort1(arr1, i, right);
}
