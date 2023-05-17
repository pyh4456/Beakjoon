#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c, num = 1;
	cin >> a >> b >> c;

	if (b >= c) {
		num = -1;
	}
	else {
		num = a / (c - b) +1 ;
	}

	cout << num;
}