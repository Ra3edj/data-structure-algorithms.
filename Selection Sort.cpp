//#include <bits/stdc++.h>
#include <iostream>
#include<algorithm>

using namespace std;

void selection_sort(int arr[], int n) {
		for (int i = 0; i < n - 1; i++)
		{
			int index = i;

			for (int j = i + 1; j < n; j++)
				if (arr[j] < arr[index]) { //descending = (arr[j] > arr[index])
					index = j;
				}
			swap(arr[index], arr[i]);

		}
}

void print(int arr[], int size)
{

	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

int main() {

	int arr[] = { 10, -4, 80, 30, 90,67 };
	int n = sizeof(arr) / sizeof(arr[0]);
	selection_sort(arr, n);
	print(arr, n);
	return 0;
}
