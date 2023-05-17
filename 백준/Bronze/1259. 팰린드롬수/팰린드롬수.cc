#include<iostream>

using namespace std;

int main() {
	string str;
	int x, y;
	bool is_palindrome;

	cin >> str;
	while (str != "0") {
		x = 0;
		y = str.length() - 1;
		is_palindrome = true;

		while (x < y) {
			if (str[x] != str[y]) {
				is_palindrome = false;
				break;
			}
			x++;
			y--;
		}
		if (is_palindrome) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
		cin >> str;
	}
}