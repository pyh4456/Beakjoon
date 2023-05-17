#include<iostream>
#include<cmath>
using namespace std;

int main() {

	int m, n, border, sum = 0, least = -1;
	bool is_prime = true;
	cin >> m >> n;

	for (int i = n; i >= m; i--) {

		is_prime = true;
		if (i == 1) is_prime = false;

		border = (int)sqrt(i);

		while (border > 1) {
			if (i % border == 0) {
				is_prime = false;
				break;
			}
			border--;
		}
		if (is_prime) {
			sum += i;
			least = i;
		}
	}
	if (least > 0) {
		cout << sum << "\n" << least;
	}
	else {
		cout << least;
	}
	
}
