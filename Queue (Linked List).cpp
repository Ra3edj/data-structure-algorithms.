//#include <bits/stdc++.h>
#include <iostream>
#include <cassert>
using namespace std;

class Queue {

	struct node {
		int data;
		node* next;
	};

	node* front, * back;
	int length;

public:

	Queue() {
		front = back = NULL;
		length = 0;
	}

	bool is_empty() {
		return length == 0;
	}

	void enqueue(int element) {
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

	void dequeue() {
		if (is_empty()) {
			cout << "the queue is empty" << endl;
		}
		else if (length == 1)
		{
			delete front;
			back = NULL;
			length = 0;
		}
		else {
			node* curr = front;
			front = front->next;
			delete curr;
		}
		length--;
	}

	void peek() {
		if (is_empty()) {
			cout << "the queue is empty" << endl;
		}
		else {
			cout << front->data << endl;
		}
	}

	void clear_queue()
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

	void print() {
		node* curr = front;
		while (curr != NULL) {
			cout << "[" << curr->data << "] ";
			curr = curr->next;
		}
	}

};

int main() {
	Queue q;
	q.enqueue(100);
	q.enqueue(200);
	q.enqueue(300);
	q.enqueue(400);
	q.dequeue();
	q.peek();
	//q.clear_queue();
	q.print();
	return 0;
}
