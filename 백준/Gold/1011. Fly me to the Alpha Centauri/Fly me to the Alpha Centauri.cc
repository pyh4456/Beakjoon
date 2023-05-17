#include <iostream>
using namespace std;

int main() {
	int num;
	long long x, y, sum = 0, n = 1, work = 0;
	bool increse = false;
	cin >> num;

	for (int i = 0; i < num; i++) {
		sum = 0, n = 1, work = 0;
		increse = false;
		cin >> x >> y;

		while (true) {
			sum += n;
			work++;
			if (increse) {
				n++;
			}

			increse = !increse;

			if (y - x <= sum) {
				break;
			}
		}

		cout << work << "\n";
	}
}