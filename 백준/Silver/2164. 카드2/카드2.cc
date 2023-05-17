#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Stack {
public:
	int* arr;
	int index;

	Stack(int n) {
		arr = new int[n];
		index = 0;
	}
	void push(int n) {
		arr[index] = n;
		index++;
	}
	int top() {
		return arr[index -1];
	}
	void pop() {
		index--;
	}
};

using namespace std;

int main() {
	int n;
	bool dump = true;
	cin >> n;

	Stack stack1(n), stack2(n);

	for (int i = 1; i <= n; i++) {
		stack2.push(i);
	}

	while (stack1.index + stack2.index > 1) {
		if (stack1.index == 0) {
			while (stack2.index > 0) {
				stack1.push(stack2.top());
				stack2.pop();
			}
		}
		else {
			if (dump) {
				stack1.pop();
				dump = false;
			}
			else {
				stack2.push(stack1.top());
				stack1.pop();
				dump = true;
			}
		}
	}

	if (stack1.index) {
		cout << stack1.top();
	}
	else {
		cout << stack2.top();
	}
	
}