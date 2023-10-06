// #include <bits/stdc++.h>
#include<iostream>

using namespace std;

template<class T> // to choose any type of data when implementation the stack 

class Stack {
	struct node {
		int data;
		node* next;
	};

	node* top;

public:

	Stack() {
		top = NULL;
	}

	bool is_empty() {
		return top == NULL;
	}

	void push(T element) {
		node* item = new node;
		if (item == NULL) {
			cout << "!!" << endl;
		}
		else {
			item->data = element;
			item->next = top;
			top = item;
		}
	}

	void pop() {
		if (is_empty()) {
			cout << "the stack is empty" << endl;
		}
		else {
			node* dlt = top;
			top = top->next;
			dlt->next = NULL;
			delete dlt;
		}
	}

	void get_top() {
		if (is_empty()) {
			cout << "the stack is empty" << endl;
		}
		else {
			cout << top -> data << endl;
		}
	}

	// to save the element in another variable when you pop it from the stack
	void pop(T& variable)
	{
		if (is_empty())
			cout << "the stack is empty" << endl;
		else {
			variable = top->data;
			node* dlt = top;
			top = top->next;
			dlt->next = NULL;
			delete dlt;
		}
	}

	void print() {
		node* curr = top;
		while (curr != NULL) {
				cout << "[" << curr->data << "]" << endl;
				curr = curr->next;
		}

	}
};

int main() {
	Stack<int>s;
	s.push(100);
	s.push(200);
	s.push(300);
	s.push(400);
	s.pop();
	s.print();

	int y;
	s.pop(y);
	cout << y << endl;
	return 0;
}
