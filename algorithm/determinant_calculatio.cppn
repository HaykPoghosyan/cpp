#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <cmath>

using namespace std;

void enter(int ** arr, int n) {
	
	cout << "Enter matrix members" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "arr[" << i << "][" << j << "] ";
			cin >> arr[i][j];
		}
		
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int ** a(int ** arr, int n, int m) {
		
	int ** barr = new int *[n-1];

	for (int i = 0; i < n-1; i++) 
  {
    barr[i] = new int[n-1];
	}
	for (int i = 0; i < n - 1; i++) 
  {
		for (int j = 0; j < n-1; j++)
    {
			if (j >= m) {
				barr[i][j] = arr[i+1][j+1];
			}
			else {
				barr[i][j] = arr[i+1][j];
			}
		}
	}
	return barr;
}

int countDeterminant(int **arr, int n) {

	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return arr[0][0];
	}
	else if (n == 2) {
		return ((arr[0][0] * arr[1][1]) - (arr[0][1] * arr[1][0]));
	}
	else {
		int sum = 0;
				
		for (int i = 0; i < n; i++) {
			int minor = pow(-1, i + 2);
			sum = sum + (minor * arr[0][i] * countDeterminant(a(arr, n, i), n - 1));
		}
		return sum;
		}
	}

int main()
{
	
	int n;
	cout << "Enter matrix rang ";
	cin >> n;

	int ** arr = new int *[n];

	for (int i = 0; i < n; i++) {
	    arr[i] = new int[n];
	}
						
	enter(arr, n);

	cout << "answer " << countDeterminant(arr, n);

    return 0;
}
