#include<iostream>

using namespace std;

int main() {
	int h, w, n, m, cnt = 0, x = 1, y = 1;

	cin >> h >> w >> n >> m;

	while (y <= h) {
		cnt++;
		x += m + 1;
		if (x > w) {
			x = 1;
			y += n + 1;
		}
	}

	cout << cnt;
}