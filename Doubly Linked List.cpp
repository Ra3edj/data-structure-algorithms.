//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class li {

	struct node {
		int data;
		node* prev ,* next;
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
			item->next = item -> prev = NULL;
		}
		else {
			front->prev = item;
			item->prev = NULL;
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
			item->prev = NULL;
		}
		else {
			item->prev = back;
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
			item->prev = curr;
			curr->next->prev = item;
			curr->next = item;
			length++;
		}
	}

	void pop_front() {
		if (is_empty()) {
			cout << "the queue is empty" << endl;
		}
		else if (length == 1) {
			delete front;
			back = front = NULL;
		}
		else {
			node* dlt = front;
			front = front->next;
			front->prev = NULL;
			delete dlt;
		}
		length--;
	}

	void pop_back() {
		if (is_empty()) {
			cout << "the queue is empty" << endl;
		}
		else if (length == 1) {
			pop_front();
		}
		else {
			node* curr = back;
			back = back->prev;
			back->next = NULL;
			delete curr;
			length--;
		}
	}

	void pop_at(int pos) {
		if (pos < 0 || pos >= length) {
			cout << "Out Of Range" << endl;
			return;
		}
		else if (is_empty()) {
			cout << "the queue is empty" << endl;
		}
		else if(0 == pos){
			pop_front();
		}
		else if (length - 1 == pos) {
			pop_back();
		}
		else{
			node* curr = front->next;


			for (int i = 1; i < pos; i++)
			{
				curr = curr->next;
			}
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			delete curr;
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

	void reverse_print() {
		if (is_empty())
		{
			cout << "the queue is empty" << endl;
		}
		else
		{
			node* curr = back;
			while (curr != NULL) {
				cout << "[" << curr->data << "] ";
				curr = curr->prev;
			}
		}

	}

	void print() {
		if (is_empty())
		{
			cout << "the queue is empty" << endl;
		}
		else {
			node* curr = front;
			while (curr != NULL) {
				cout << "[" << curr->data << "] ";
				curr = curr->next;
			}
		}
	}

};
int main() {
	li l;
	l.push_front(100);
	l.push_front(200);
	l.push_front(300);
	l.push_front(400);
	l.push_back(500);
	l.pop_back();
	l.pop_front();
	l.push_at(1, 543);
	l.pop_at(2);
	//l.reverse_print();
	//l.clear_list();
	l.print();
	return 0;
}
