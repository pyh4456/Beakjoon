#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num, distance = 1, sum = 1;
	cin >> num;

	while (true) {
		if (num <= sum) break;

		sum += distance * 6;
		distance++;
	}

	cout << distance;
}