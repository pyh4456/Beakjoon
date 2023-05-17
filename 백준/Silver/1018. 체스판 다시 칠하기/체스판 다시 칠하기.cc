#include<iostream>
using namespace std;

char** board;

int repaint(int x, int y) {
	int least, cnt = 0;

	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if ((i + j) % 2 == 1) {
				if (board[i][j] != 'W') {
					cnt++;
				}
			}
			else {
				if (board[i][j] != 'B') {
					cnt++;
				}
			}
		}
	}
	least = cnt;
	cnt = 0;

	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if ((i + j) % 2 == 0) {
				if (board[i][j] != 'W') {
					cnt++;
				}
			}
			else {
				if (board[i][j] != 'B') {
					cnt++;
				}
			}
		}
	}

	if (cnt < least) least = cnt;
	return least;
}

int main() {
	int m, n, least = 64, out;

	cin >> m >> n;

	board = new char*[m];
	for (int i = 0; i < m; i++) {
		board[i] = new char[n];
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < m - 7; i++) {
		for (int j = 0; j < n - 7; j++) {
			out = repaint(i, j);
			if (least > out) {
				least = out;
			}
		}
	}

	

	cout << least;
}