#include<iostream>
using namespace std;

int n, ** house;

enum direction {
	RIGHT, DIAGONAL, DOWN
};

bool canMove(int r, int c, direction direct, direction current_direct) {

	switch (current_direct) {
	case RIGHT:
		switch (direct) {
		case RIGHT:
			if (c == n - 2) return false;
			return !house[r][c + 2];
			break;
		case DIAGONAL:
			if (c == n - 2 || r == n - 1) return false;
			return !(house[r][c + 2] || house[r + 1][c + 2] || house[r + 1][c + 1]);
			break;
		}
		break;
	case DIAGONAL:
		switch (direct) {
		case RIGHT:
			if (c == n - 2) return false;
			return !house[r + 1][c + 2];
			break;
		case DIAGONAL:
			if (c == n - 2 || r == n - 2) return false;
			return !(house[r + 1][c + 2] || house[r + 2][c + 2] || house[r + 2][c + 1]);
			break;
		case DOWN:
			if (r == n - 2) return false;
			return !house[r + 2][c + 1];
			break;
		}
		break;
	case DOWN:
		switch (direct) {
		case DIAGONAL:
			if (c == n - 1 || r == n - 2) return false;
			return !(house[r + 1][c + 1] || house[r + 2][c + 1] || house[r + 2][c]);
			break;
		case DOWN:
			if (r == n - 2) return false;
			return !house[r + 2][c];
			break;
		}
		break;
	}
}

int move(int r, int c, direction direct) {
	int num = 0;

	switch (direct) {
	case RIGHT:
		if (r == n - 1 && c == n - 2) return 1;

		if (canMove(r, c, RIGHT, RIGHT)) {
			num += move(r, c + 1, RIGHT);
		}
		if (canMove(r, c, DIAGONAL, RIGHT)) {
			num += move(r, c + 1, DIAGONAL);
		}
		break;
	case DIAGONAL:
		if (r == n - 2 && c == n - 2) return 1;

		if (canMove(r, c, RIGHT, DIAGONAL)) {
			num += move(r + 1, c + 1, RIGHT);
		}
		if (canMove(r, c, DIAGONAL, DIAGONAL)) {
			num += move(r + 1, c + 1, DIAGONAL);
		}
		if (canMove(r, c, DOWN, DIAGONAL)) {
			num += move(r + 1, c + 1, DOWN);
		}
		break;
	case DOWN:
		if (r == n - 2 && c == n - 1) return 1;

		if (canMove(r, c, DIAGONAL, DOWN)) {
			num += move(r + 1, c, DIAGONAL);
		}
		if (canMove(r, c, DOWN, DOWN)) {
			num += move(r + 1, c, DOWN);
		}
		break;
	}
	return num;
}

int main() {

	cin >> n;

	house = new int* [n];
	for (int i = 0; i < n; i++) {
		house[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> house[i][j];
		}
	}

	cout << move(0, 0, RIGHT);
}