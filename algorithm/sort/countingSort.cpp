
#include "stdafx.h"
#include <iostream>

using namespace std;

void print(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void countingSort(int * arr, int * brr, int n) {
	for (int i = 0; i < n; i++) {
		brr[arr[i]]++;
	}
  
	int k = 0;
  
	for (int i = 0; i < 10; i++) {
		for (int j = 0 ; j < brr[j]; j++) {
			arr[k] = i;
			k++;
		}
	}
}

int main()
{
	int brr[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int n;
	cin >> n;
	int * arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	print(arr, n);

	countingSort(arr, brr, n);

	print(arr, n);
  
  return 0;
}


