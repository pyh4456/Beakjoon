#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

class Queue {
public:
	int _front;
	int _rear;
	int _size;
	int _arraysize;
	int* data;
	Queue(int n) {
		this->_size = 0;
		this->_arraysize = n;
		this->data = new int[n];
		this->_front = 0;	//가장앞의 index
		this->_rear = 0;	//가장뒤의 index + 1
	}
	void push(int n);
	void pop();
	int size();
	bool isFull();
	bool empty();
	int front();
	int back();
};

bool Queue::isFull() {
	return _size == _arraysize;
}

void Queue::push(int n) {
	if (!this->isFull()) {
		data[_rear] = n;
		_rear++;
		if (_rear == _arraysize)
			_rear = 0;
		
		_size++;
	}
}

void Queue::pop() {
	if(!empty()) {
		_front++;
		if (_front == _arraysize)
			_front = 0;
		_size--;
	}
}

int Queue::size() {
	return _size;
}

bool Queue::empty() {
	return _size == 0;
}

int Queue::front() {
	if (empty()) return -1;
	return data[_front];
}

int Queue::back() {
	if (empty()) return -1;
	return data[_rear - 1];
}

enum command {
	push,
	pop,
	size,
	empty,
	front,
	back
};

int commandToEnum(char command[6]) {
	if (strcmp(command, "push") == 0) {
		return 0;
	}
	else if (strcmp(command, "pop") == 0) {
		return 1;
	}
	else if (strcmp(command, "size") == 0) {
		return 2;
	}
	else if (strcmp(command, "empty") == 0) {
		return 3;
	}
	else if (strcmp(command, "front") == 0) {
		return 4;
	}
	else if (strcmp(command, "back") == 0) {
		return 5;
	}

	return 6;
}

int main() {
	int n, num;
	char cmd[6];
	int c;
	Queue queue(10000);

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%s", cmd);

		c = commandToEnum(cmd);

		switch (c) {
		case 0:
			cin >> num;
			queue.push(num);
			break;
		case 1:
			cout << queue.front() << endl;
			queue.pop();
			break;
		case 2:
			cout << queue.size() << endl;
			break;
		case 3:
			cout << queue.empty() << endl;
			break;
		case 4:
			cout << queue.front() << endl;
			break;
		case 5:
			cout << queue.back() << endl;
		}
	}
}