#include <stdio.h>
#include "BinaryTree3.h"


//////////////User TweetȽ�� ���� QuickSort////
void Swap(BTreeNode* arr[], int idx1, int idx2)
{
	BTreeNode* temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}


int Partition(BTreeNode* arr[], int left, int right)
{
	int pivot = arr[left]->numOfTweets;    // �ǹ��� ��ġ�� ���� ����! 
	int low = left + 1;
	int high = right;

	while (low <= high)    // �������� ���� ������ �ݺ�
	{
		while (pivot >= arr[low]->numOfTweets && low <= right)
			low++;

		while (pivot <= arr[high]->numOfTweets && high >= (left + 1))
			high--;

		if (low <= high)    // �������� ���� ���¶�� Swap ����
			Swap(arr, low, high);    // low�� high�� ����Ű�� ��� ��ȯ
	}

	Swap(arr, left, high);    // �ǹ��� high�� ����Ű�� ��� ��ȯ
	return high;    // �Ű��� �ǹ��� ��ġ ���� ��ȯ
}

void QuickSort(BTreeNode* arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);    // �ѷ� ������ 
		QuickSort(arr, left, pivot - 1);    // ���� ������ ����
		QuickSort(arr, pivot + 1, right);    // ������ ������ ����
	}
}


//////////// Word ���� ���� QuickSort ////////
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
