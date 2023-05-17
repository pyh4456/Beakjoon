#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Linked_list {
public:
	int data;
	Linked_list* prev;
	Linked_list* next;

	Linked_list(int n) {
		data = n;
		prev = nullptr;
		next = nullptr;
	}

	void push_back(int n) {
		if (next == nullptr) {
			next = new Linked_list(n);
			next->prev = this;
		}
		else {
			next->push_back(n);
		}
	}
	Linked_list* Delete() {
		prev->next = next;
		next->prev = prev;

		return next;
	}
	Linked_list* last() {
		if (next == nullptr) {
			return this;
		}
		
		return next->last();
	}
};

void josephus(int n, int k, Linked_list* list) {
	Linked_list* buffer = list;

	if (n == 1) {
		cout << list->data << ">";
		return;
	}

	for (int i = 1; i < k; i++) {
		buffer = buffer->next;
	}
	cout << buffer->data;
	if (n > 1) {
		cout << ", ";
	}
	buffer = buffer->Delete();

	josephus(n - 1, k, buffer);
}

int main() {
	int n, k;
	Linked_list list(1);
	cin >> n >> k;

	for (int i = 2; i <= n; i++) {
		list.push_back(i);
	}
	list.prev = list.last();
	list.last()->next = &list;

	cout << "<";
	josephus(n, k, &list);
}