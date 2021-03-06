
#include "stdafx.h"
#include <iostream>

using namespace std;

void print(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

void bubbleSort(int arr[], int n)
{
	if (n == 1) {
		return;
	}
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			swap(arr[i], arr[i + 1]);
		}
	}
	bubbleSort(arr, n - 1);
}

int main()
{
	int n;
	cin >> n;
	int * arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	print(arr, n);

	bubbleSort(arr, n);

	print(arr, n);

	return 0;
}

