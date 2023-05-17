#include<iostream>
using namespace std;

int main() {
	int biggest = 0, n, x = 1, y = 1;
	
	for (int i = 0; i < 81; i++) {
		cin >> n;
		if (biggest < n) {
			biggest = n;
			x = i / 9 + 1;
			y = i % 9 + 1;
		}
	}
	cout << biggest << "\n" << x << " " << y;
}