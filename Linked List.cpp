//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class li {

	struct node {
		int data;
		node* next;
	};

	node* front, * back;
	int length;

public:

	li() {
		front = back = NULL;
		length = 0;
	}

	bool is_empty() {
		return length == 0;
	}

	void push_front(int element) {
		node* item = new node;
		item->data = element;
		if (is_empty()) {
			front = back = item;
			item->next = NULL;
		}
		else {
			item->next = front;
			front = item;
		}
		length++;
	}

	void push_back(int element) {
		node* item = new node;
		item->data = element;
		item->next = NULL;
		if (is_empty()) {
			front = back = item;
		}
		else {
			back->next = item;
			back = item;
		}
		length++;
	}

	void push_at(int pos, int element) {
		node* item = new node;
		item->data = element;
		if (pos < 0 || pos > length) {
			cout << "out of range" << endl;
		}
		else if (pos == 0) {
			push_front(element);
		}
		else if (pos == length) {
			push_back(element);
		}
		else {
			node* curr = front;
			for (int i = 1; i < pos; i++) {
				curr = curr->next;
			}
			item->next = curr->next;
			curr->next = item;
			length++;
		}
	}

	void pop_front() {
		if (is_empty()) {
			cout << "the queue is empty" << endl;
		}
		else {
			node* dlt = front;
			front = front->next;
			delete dlt;
			length--;
		}
	}

	void pop_back() {
		if (is_empty()) {
			cout << "the queue is empty" << endl;
		}
		else if (length == 1) {
			pop_front();
		}
		else {
			node* curr = front;
			while (curr->next != back) {
				curr = curr->next;
			}
			delete back;
			curr->next = NULL;
			back = curr;
			length--;
		}
	}

	void pop_element(int element) {
		if (is_empty()) {
			cout << "the queue is empty" << endl;
		}
		else if(front -> data == element){
			pop_front();
		}
		else if (back->data == element) {
			pop_back();
		}
		else{
			node* prev = front;
			node* curr = front->next;
			while (curr != NULL) {
				if (curr->data == element) {
					break;
				}
				prev = curr;
				curr = curr->next;
			}
			if (curr == NULL) {
				cout << "The item is not there" << endl;
			}
			else {
				prev->next = curr->next;
				back = prev;
				delete curr;
				length--;
			}
		}
	}

	void clear_list()
	{
		node* curr;
		while (front != NULL)
		{
			curr = front;
			front = front->next;
			delete curr;
		}
		back = NULL;
		length = 0;
	}

	void reverse() {
		node* prev, * next, * curr;
		prev = NULL;
		curr = front;
		next = curr->next;
		while (next != NULL)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		front = prev;
	}

	void print() {
		node* curr = front;
		while (curr != NULL) {
			cout << "[" << curr->data << "] ";
			curr = curr->next;
		}
	}

};
int main() {
	li l;
	l.push_front(100);
	l.push_front(200);
	l.push_front(300);
	l.push_front(400);
	l.pop_front();
	l.push_back(500);
	l.pop_back();
	l.push_at(1, 5645);
	l.pop_element(200);
	l.reverse();
	
	//l.clear_list();
	l.print();
	return 0;
}
