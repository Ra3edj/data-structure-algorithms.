//#include <bits/stdc++.h>
#include <iostream>
#include<algorithm>

using namespace std;

int q(int arr[], int ib, int je) { // b = begin , e = end
	int i = ib;
	int j = je;
	int pivloc = i;
	while (1){
		while (arr[pivloc] <= arr[j] && pivloc != j){
			j--;
		}
		if (pivloc == j) {
			break;
		}
		else if (arr[pivloc] > arr[j]){
			swap(arr[j], arr[pivloc]);
			pivloc = j;
		}

		while (arr[pivloc] >= arr[i] && pivloc != i)
		{
			i++;
		}
		if (pivloc== i)
			break;
		else if (arr[pivloc] < arr[i])
		{
			swap(arr[i], arr[pivloc]);
			pivloc = i;
		}
	}
	return pivloc;
}


void quick_sort(int arr[], int l, int h)
{

	if (l < h) {
		int q1 = q(arr, l, h);
		quick_sort(arr, l, q1 - 1);
		quick_sort(arr,q1 + 1, h);
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
	quick_sort(arr, 0 , n - 1);
	print(arr, n);
	return 0;
}
