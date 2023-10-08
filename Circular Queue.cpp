//#include <bits/stdc++.h>
#include <iostream>
#include <cassert>
using namespace std;

class Queue {
	int front, back , length, mx;
	int* arr;

public:

	Queue(int size = 100){
		if (size <= 0) {
			mx = 100;
		}
		else {
			mx = size;
			front = 0;
			back = mx - 1;
			length = 0;
			arr = new int[mx];
		}
		
	}

	bool is_empty() {
		return length == 0;
	}

	bool is_full() {
		return length == mx;
	}

	void enqueue(int element) {
		if (is_full()) {
			cout << "the queue is full" << endl;
		}
		else {
			back = (back + 1) % mx;
			arr[back] = element;
		}
		length++;
	}

	void  dequeue() {
		if (is_empty()) {
			cout << "the queue is empty" << endl;
		}
		else {
			front = (front + 1) % mx;
			length--;
		}
	}

	void peek() {
		if (is_empty()) {
			cout << "the queue is empty" << endl;
		}
		else {
			cout << arr[front] << endl;
		}
	}

	void search(int element) {
		if (is_empty()) {
			cout << "the queue is empty" << endl;
		}
		else {
			for (int i = front; i != back + 1; i++) {
				if (arr[i] == element) {
					cout << i << endl;
					return;
				}
			}
			cout << "the element doesn't exist in the queue" << endl;
		}
	}

	void print() {
		if (is_empty()) {
			cout << "the queue is empty" << endl;
		}
		else {
			for (int i = front; i != back + 1; i++) {
				cout << "[" << arr[i] << "] ";
			}
		}
	}
};
int main() {
	Queue q;
	q.enqueue(100);
	q.enqueue(200);
	q.enqueue(300);
	q.dequeue();
	q.peek();
	q.search(200);
	q.print();
	return 0;
}
