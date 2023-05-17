#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int num, first_row = 1, i = 0;
	cin >> num;

	while (true) {
		if (num <= first_row + i) {
			break;
		}
		i++;

		first_row += i;
		
	}
	if (i % 2 == 0) {
		cout << 1 + i - (num - first_row) << "/" << 1 + (num - first_row);
	}
	else {
		cout << 1 + (num - first_row) << "/" << 1 + i - (num - first_row);
	}
}