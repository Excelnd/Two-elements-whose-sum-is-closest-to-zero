// Two elements whose sum is closest to zero.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void quickSort(int *, int, int);

void minAbsSumPair(int arr[], int n)
{
	int sum, min_sum = INT_MAX;
	int l = 0, r = n - 1;
	int min_l = l, min_r = n - 1;

	if (n < 2)
	{
		printf("Invalid Input");

		return;
	}

	quickSort(arr, l, r);

	while (l < r) {
		sum = arr[l] + arr[r];
		if (abs(sum) < abs(min_sum))
		{
			min_sum = sum;
			min_l = l;
			min_r = r;

		}
		if (sum < 0)
			l++;
		else
			r--;
	}

	printf(" The two elements whose sum is minimum are %d and %d",
						arr[min_l], arr[min_r]);
}

int main()
{

	int arr[] = { 1, 60, -10, 70, -80, 85 };
	int n = sizeof(arr) / sizeof(arr[0]);
	minAbsSumPair(arr, n);
	getchar();

    return 0;
}


void exchange(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int si, int ei) {

	int x = arr[ei];
	int i = (si - 1);
	int j;

	for (j = si; j <= ei - 1; j++) {
		if (arr[j] <= x)
		{
			i++;
			exchange(&arr[i], &arr[j]);

		}
	}

	exchange(&arr[i + 1], &arr[ei]);

	return(i + 1);
}

void quickSort(int arr[], int si, int ei)
{
	int pi;

	if (si < ei)
	{
		pi = partition(arr, si, ei);
		quickSort(arr, si, pi - 1);
		quickSort(arr, pi + 1, ei);

	}
}
