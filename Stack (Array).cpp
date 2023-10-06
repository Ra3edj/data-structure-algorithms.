// #include <bits/stdc++.h>
#include<iostream>

using namespace std;

const int max_size = 100; 
template<class T> // to choose any type of data when implementation the stack 

class Stack {
	int top;
	T arr[max_size];

public:

	Stack() {
		top = -1;
	}

	bool is_empty() {
		return top == -1;
	}

	bool is_full() {
		return top == max_size - 1;
	}

	void push(T element) {
		if (is_full()) {
			cout << "the stack is full" << endl;
		}
		else {
			top++;
			arr[top] = element;
		}
	}

	void pop() {
		if (is_empty()) {
			cout << "the stack is empty" << endl;
		}
		else {
			top--;
		}
	}

	void get_top() {
		if (is_empty()) {
			cout << "the stack is empty" << endl;
		}
		else {
			cout << arr[top] << endl;
		}
	}

 // to save the element in another variable when you pop it from the stack
	void pop(T& variable)
	{
		if (is_empty())
			cout << "the stack is empty" << endl;
		else {
			variable = arr[top];
			top--;
		}
	}

	void search_index(int element) {
		if (is_empty()) {
			cout << "the stack is empty" << endl;
		}
		else {
			for (int i = top; i >= 0; i--) {
				if (arr[i] == element) {
					cout << i << endl;
					return;
				}
			}
			 cout << "The element doesn't exist" << endl;
		}
	}


	void print() {
		for (int i = top; i >= 0; i--)
		{
			cout << "[" << arr[i] << "]" << endl;
		}
		cout << endl;

	}
};

int main() {
	Stack<int>s;
	s.push(100);
	s.push(200);
	s.push(300);
	s.push(400);
	s.pop();
	s.search_index(200);
	s.print();

	int y;
	s.pop(y);
	cout << y << endl;
	return 0;
}
