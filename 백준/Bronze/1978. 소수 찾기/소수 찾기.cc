#include<iostream>
#include<cmath>
using namespace std;

int main() {

	int n, num, border, num_of_prime = 0;
	bool is_prime = true;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		is_prime = true;
		if (num == 1) is_prime = false;

		border = (int)sqrt(num);

		while (border > 1) {
			if (num % border == 0) {
				is_prime = false;
				break;
			}
			border--;
		}
		

		if (is_prime) num_of_prime++;
	}

	cout << num_of_prime;
}
