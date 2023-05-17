#include <iostream>
using namespace std;

int main() {
	int n, pack = 0, sum = 0, five_kg;

	cin >> n;

	pack += n / 5;
	sum = pack * 5;
	five_kg = pack;

	while (true) {
		if (sum < n) {
			sum += 3;
			pack++;
		}
		else if (sum > n) {
			sum = sum - 5;
			pack--;
			five_kg--;
			if (five_kg < 0) {
				pack = -1;
				break;
			}
		}
		else {
			break;
		}
	}
	cout << pack;
}