#include<iostream>
#include<math.h>
using namespace std;

int getFirstDigitOfPOW(int a, int b) {
	int out = a % 10;
	while (b > 1) {
		out = (out * (a % 10)) % 10;
		b--;
	}
	if (out == 0) out = 10;
	return out;
}

int main() {
	int t, a, b;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> a >> b;

		cout << getFirstDigitOfPOW(a, b) << endl;
	}
}