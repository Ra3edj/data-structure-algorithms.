//#include <bits/stdc++.h>
#include <iostream>
#include<algorithm>

using namespace std;

void heapy(int arr[], int n, int i)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int max = i;
	if (l < n && arr[l] > arr[max]) {
		max = l;
	}
	if (r<n && arr[r] > arr[max]) {
		max = r;
	}
	if (max != i) {
		swap(arr[i], arr[max]);
		heapy(arr, n, max);
	}
}

void heap_b(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapy(arr, n, i);
}

void heap_sort(int arr[], int n)
{

	heap_b(arr, n);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapy(arr, i, 0);
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
	heap_sort(arr, n);
	print(arr, n);
	return 0;
}
