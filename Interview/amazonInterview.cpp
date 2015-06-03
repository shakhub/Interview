#include<stdio.h>
#include<stdlib.h>
#include"stacks.hpp"
/*
Given an integer array A of size n. Given an integer k < n. Construct an array B, such that
B[i] = min{A[i], A[i+1], A[i+2], A[i+3], ……., A[i+k]}
Solve in time complexity better than O(nk).
Hint: use min Heaps
*/

int minSpecial(int *A, int start, int end)
{
	int min = A[start];
	int i = 0;
	
	for (i = start+1; i <= end; i++)
	{
		if (A[i] < min)
			min = A[i];
	}
	return min;
}
void minArray(int *A, int n, int k)
{
	int i = 0;
	int *B = (int*)malloc((n - k)*sizeof(int));   

	for (i = 0; i < n; i++)
	{
		if ((i + k) > n - 1) return;
		B[i] = minSpecial(A, i, i + k);
		printf("B[%d] = %d\n", i, B[i]);
	}
	
}


void runAmazonInterview()
{
	int A[8] = { 3, 9, 5, 4, 1, 8, 11, 10 };

	minArray(A, 8, 5); // brute force method O(nk)
	
}