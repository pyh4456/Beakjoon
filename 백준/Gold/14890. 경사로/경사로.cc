#include<iostream>

using namespace std;

int n, l, **map, out = 0;

bool can_go_up(int y, int x, int* runway, int mode) {	//mode = 0 : horizontal, mode = 1 : vertical
	int standard = map[y][x];

	if (mode == 0) {
		if (x - (l - 1) < 0) return false;

		for (int i = 0; i < l; i++) {
			if (map[y][x - i] != standard || runway[x - i] == 1) {
				return false;
			}
		}

		for (int q = 0; q < l; q++) {
			runway[x - q] = 1;
		}
		return true;
	}
	else {
		if (y - (l - 1) < 0) return false;

		for (int i = 0; i < l; i++) {
			if (map[y - i][x] != standard || runway[y - i] == 1) {
				return false;
			}
		}

		for (int q = 0; q < l; q++) {
			runway[y - q] = 1;
		}
		return true;
	}
}

bool can_go_down(int y, int x, int* runway, int mode) {	//mode = 0 : horizontal, mode = 1 : vertical
	int standard;

	if (mode == 0) {
		standard = map[y][x + 1];
		if (x + l >= n) return false;

		for (int i = 0; i < l; i++) {
			if (map[y][x + i + 1] != standard) {
				return false;
			}
		}
	
		for (int q = 0; q < l; q++) {
			runway[x + q + 1] = 1;
		}

		return true;
	}
	else {
		standard = map[y + 1][x];
		if (y + l >= n) return false;

		for (int i = 0; i < l; i++) {
			if (map[y + i + 1][x] != standard) {
				return false;
			}
		}

		for (int q = 0; q < l; q++) {
			runway[y + q + 1] = 1;
		}
		return true;
	}
}



int count_path() {
	int cnt = 0;
	bool passable = true;
	int* runway = new int[n];	//경사로 위치 체크

	//horizontal path
	for (int i = 0; i < n; i++) {	
		passable = true;
		
		for (int j = 0; j < n; j++) {	//경사로 위치 초기화
			runway[j] = 0;
		}
		for (int j = 0; j < n - 1; j++) {
			if (map[i][j] == map[i][j + 1]) {
				continue;
			}
			else {
				if (map[i][j] - map[i][j + 1] == 1) {	//내려가야 하는 상황
					if (!can_go_down(i, j, runway, 0)) {
						passable = false;
						break;
					}
				}
				else if (map[i][j] - map[i][j + 1] == -1) {	//올라가야 하는 상황
					if (!can_go_up(i, j, runway, 0)) {
						passable = false;
						break;
					}
				}
				else {
					passable = false;
					break;
				}
			}
		}
		if (passable)
			cnt++;
	}

	//vertical path
	for (int j = 0; j < n; j++) {
		passable = true;

		for (int i = 0; i < n; i++) {	//경사로 위치 초기화
			runway[i] = 0;
		}
		for (int i = 0; i < n - 1; i++) {
			if (map[i][j] == map[i + 1][j]) {
				continue;
			}
			else {
				if (map[i][j] - map[i + 1][j] == 1) {	//내려가야 하는 상황
					if (!can_go_down(i, j, runway, 1)) {
						passable = false;
						break;
					}
				}
				else if (map[i][j] - map[i + 1][j] == -1) {	//올라가야 하는 상황
					if (!can_go_up(i, j, runway, 1)) {
						passable = false;
						break;
					}
				}
				else {
					passable = false;
					break;
				}
			}
		}
		if (passable)
			cnt++;
	}

	return cnt;
}

int main() {
	cin >> n >> l;

	map = new int* [n];

	for (int i = 0; i < n; i++) {
		map[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	out = count_path();

	cout << out;
}