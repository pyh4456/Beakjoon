#include<iostream>

using namespace std;

int** paper, confetti[5] = { 5, 5, 5, 5, 5 }, least = 25, cnt = 0;

bool glue_confetti(int size, int row, int column) {//size : 0 ~ 4
	bool out = true;

	if (confetti[size] > 0 && row + size < 10 && column + size < 10) {
		int i = 0, j = -1;

		while (i < size || j < size) {
			j++;
			if (j > size) {
				i++;
				j = 0;
			}
			if (!paper[row + i][column + j]) {
				out = false;
				break;
			}
			
		}

	}else{
		out = false;
	}
	if (out) {
		confetti[size]--;

		for (int i = 0; i <= size; i++) {
			for (int j = 0; j <= size; j++) {
				paper[row + i][column + j] = 0;
			}
		}
	}

	return out;
}

void unglue_confetti(int size, int row, int column) {
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= size; j++) {
			paper[row + i][column + j] = 1;
		}
	}
	confetti[size]++;
}

bool isClean() {
	for (int a = 0; a < 10; a++) {
		for (int b = 0; b < 10; b++) {
			if (paper[a][b]) return false;
		}
	}
	return true;
}

bool recursion(int row, int column) {
	bool clean = false;
	int i = 0, j = 0;

	if (isClean()) {
		if (cnt < least) {
			least = cnt;
		}
		return true;
	}

	while (i < 10 || j < 10) {
		if (paper[i][j]) {
			for (int k = 4; k >= 0; k--) {

				if (glue_confetti(k, i, j)) {
					cnt++;

					if (recursion(i, j)) {
						clean = true;
					}
					unglue_confetti(k, i, j);
					cnt--;
				}
			}
			break;
		}
		j++;
		if (j == 10) {
			i++;
			j = 0;
		}
	}
			
	

	return clean;
}

int main() {
	int cnt = 0;

	paper = new int* [10];
	paper[0] = new int[10];
	paper[1] = new int[10];
	paper[2] = new int[10];
	paper[3] = new int[10];
	paper[4] = new int[10];
	paper[5] = new int[10];
	paper[6] = new int[10];
	paper[7] = new int[10];
	paper[8] = new int[10];
	paper[9] = new int[10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> paper[i][j];
		}
	}

	
	if (recursion(0, 0)) {
		cout << least;
	}else{
		cout << -1;
	}
}