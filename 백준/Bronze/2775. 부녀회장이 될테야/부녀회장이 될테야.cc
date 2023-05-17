#include <iostream>
#include<vector>
using namespace std;

int main() {
	int num_of_case, k, n, sum = 0;

	cin >> num_of_case;

	for (int i = 0; i < num_of_case; i++) {
		cin >> k >> n;
		

		vector<int> vector(n);
		for (int k = 0; k < vector.size(); k++) {
			vector[k] = k + 1;
		}

		for (int j = 0; j < k; j++) {
			sum = 0;
			for (int k = 0; k < vector.size(); k++) {
				sum += vector[k];
				vector[k] = sum;
			}
		}
		cout << vector[n - 1] << "\n";
	}
}