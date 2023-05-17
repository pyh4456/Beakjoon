#include<iostream>

using namespace std;

bool is_decomposition(int m, int n, int digit) {
	int sum = n;
	for (int i = 0; i < digit; i++) {
		sum += n % 10;
		n = n / 10;
	}

	if (m == sum) return true;
	else return false;
}

int main() {
	int m, temp, digit = 0, decomposition = 0;

	cin >> m;

	temp = m;

	while (temp > 0) {
		temp = temp / 10;
		digit++;
	}

	for (int i = m -10 * digit; i < m; i++){
		if (is_decomposition(m, i, digit)) {
			decomposition = i;
			break;
		}
	}
	cout << decomposition;
}