//#include <bits/stdc++.h>
#include <iostream>
#include<algorithm>

using namespace std;
void merge(int arr[], int l, int m, int r)       
{
	int n1 = m - l + 1;                  
	int n2 = r - m;                    
	int* l1 = new int[n1], * r1 = new int[n2];

	int i, j, k;
	for (i = 0; i < n1; i++) {
		l1[i] = arr[l + i];
	}

	for (j = 0; j < n2; j++) {
		r1[j] = arr[m + 1 + j];
	}

	i = j = 0;
	k = l;

	while (i < n1 && j < n2){
		if (l1[i] <= r1[j]) { // //descending = (l1[i] >= r1[j])
			arr[k] = l1[i];
			i++;
		}
		else{
			arr[k] = r1[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = l1[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = r1[j];
		j++;
		k++;
	}
}


void merge_sort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);

		merge(arr, l, m, r);
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
	merge_sort(arr, 0 , n - 1);
	print(arr, n);
	return 0;
}
