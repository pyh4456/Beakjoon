#include<iostream>
#include<cmath>
using namespace std;

int main() {

	int m, n, border;
	bool is_prime = true;
	cin >> m >> n;

	for (int i = m; i <= n; i++) {

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
			cout << i << "\n";
		}
	}
}
