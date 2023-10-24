//#include <bits/stdc++.h>
#include <iostream>
#include<algorithm>

using namespace std;

void bubble_sort(int arr[], int n)
{
	bool t_f = true;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) //descending = (arr[j] < arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				t_f = false;
			}
		}
		if (t_f == true)
			break;

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
	bubble_sort(arr, n);
	print(arr, n);
	return 0;
}
