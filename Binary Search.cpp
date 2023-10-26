//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int binary_search(int arr[], int l, int h, int e)
{
	while (l <= h) {

		int m = (l + h) / 2;

		if (arr[m] == e) {
			return m;
		}
		if (arr[m] > e) {
			h = m - 1;
		}
		else {
			l = m + 1;
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

	int r = binary_search(arr, 0 , n - 1, num);
	if (r == 0) {
		cout << "error , the number not found";
	}
	else {
		cout << r;
	}



	return 0;
}
