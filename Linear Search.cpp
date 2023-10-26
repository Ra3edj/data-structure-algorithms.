//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int linear_search(int arr[], int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == k) {
			return i;
		}
	}
	return 0;
}


int main()
{
	int arr[] = { 54,534,55,90,100 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int num;
	cout << "enter the number:";
	cin >> num;

	int r = linear_search(arr, n, num);
	if (r == 0) {
		cout << "error , the number not found";
	}
	else {
		cout << r;
	}



	return 0;
}
