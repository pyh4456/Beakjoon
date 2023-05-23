#include<iostream>
#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

using namespace std;

int n, m, x, y, k;
int** map;

int roll(int dice[6], int command) {
	static int top = 0; //현재의 윗면 위치 
	int temp;

	switch (command) {
	case 1:	//right
		temp = dice[5];
		dice[5] = dice[2];
		dice[2] = dice[0];
		dice[0] = dice[3];
		dice[3] = temp;
		break;
	case 2:	//left
		temp = dice[5];
		dice[5] = dice[3];
		dice[3] = dice[0];
		dice[0] = dice[2];
		dice[2] = temp;
		break;
	case 3:	//up
		temp = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[0];
		dice[0] = dice[4];
		dice[4] = temp;
		break;
	case 4:	//down
		temp = dice[5];
		dice[5] = dice[4];
		dice[4] = dice[0];
		dice[0] = dice[1];
		dice[1] = temp;
		break;
	}

	if (map[x][y] == 0) {
		map[x][y] = dice[5];
	}
	else {
		dice[5] = map[x][y];
		map[x][y] = 0;
	}

	return dice[top];
}

int main() {
	int dice[6] = { 0 };
	int *command;
	cin >> n >> m;

	map = new int* [n];
	for (int i = 0; i < n; i++) {
		map[i] = new int[m];
	}
	cin >> x >> y >> k;

	command = new int[k];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> command[i];
	}

	for (int i = 0; i < k; i++) {
		switch (command[i]) {
		case 1:
			if (y == m - 1) {
				continue;
			}
			y++;
			break;
		case 2:
			if (y == 0) {
				continue;
			}
			y--; break;
		case 3:
			if (x == 0) {
				continue;
			}
			x--; break;
		case 4:
			if (x == n - 1) {
				continue;
			}
			x++; break;
		}
		cout << roll(dice, command[i]) << endl;
	}

}