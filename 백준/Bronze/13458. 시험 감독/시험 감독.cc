#include <iostream>

using namespace std;

int main() {
	int n, b, c, buffer;
	int* test_site;
	long long cnt = 0;

	cin >> n;

	test_site = new int[n];
	for (int i = 0; i < n; i ++) {
		cin >> test_site[i];
	}
	cnt += n;
	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		buffer = test_site[i];
		buffer -= b;
		if (buffer <= 0) continue;

		cnt += (buffer / c);
		if (buffer % c > 0)
			cnt++;
	}

	cout << cnt;
}