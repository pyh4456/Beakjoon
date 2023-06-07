#include<iostream>
#include<vector>
using namespace std;

class Camera {
public:
	int y;
	int x;
	int type;
	//1타입 1: 위쪽 방향, 2: 오른쪽 방향, 3: 아래쪽 방향, 4: 왼쪽 방향
	//2타입 1: 가로 방향, 2: 세로방향
	//3타입 1: 』 방향, 2,3,4 : 순차적으로 시계방향 회전
	//4타입 1: ㅗ 방향, 2,3,4 : 순차적으로 시계방향 회전
	
	void watch(int**& room, int n, int m, int direction) {
		int cnt, greatest;
		switch (type) {
		case 5:
			for (int i = y; i >= 0; i--) {	//위쪽
				if (room[i][x] == 0)
					room[i][x] = 7;
				else if (room[i][x] == 6)
					break;
			}
			for (int i = x; i < m; i++) {	//오른쪽
				if (room[y][i] == 0)
					room[y][i] = 7;
				else if (room[y][i] == 6)
					break;
			}
			for (int i = y; i < n; i++) {	//아래쪽
				if (room[i][x] == 0)
					room[i][x] = 7;
				else if (room[i][x] == 6)
					break;
			}
			for (int i = x; i >= 0; i--) {	//왼쪽
				if (room[y][i] == 0)
					room[y][i] = 7;
				else if (room[y][i] == 6)
					break;
			}
			break;
		case 4:
			if (direction == 1) {
				for (int i = y; i >= 0; i--) {	//위쪽
					if (room[i][x] == 0)
						room[i][x] = 7;
					else if (room[i][x] == 6)
						break;
				}
				for (int i = x; i < m; i++) {	//오른쪽
					if (room[y][i] == 0)
						room[y][i] = 7;
					else if (room[y][i] == 6)
						break;
				}
				for (int i = x; i >= 0; i--) {	//왼쪽
					if (room[y][i] == 0)
						room[y][i] = 7;
					else if (room[y][i] == 6)
						break;
				}
			}
			else if (direction == 2) {
				for (int i = y; i >= 0; i--) {	//위쪽
					if (room[i][x] == 0)
						room[i][x] = 7;
					else if (room[i][x] == 6)
						break;
				}
				for (int i = x; i < m; i++) {	//오른쪽
					if (room[y][i] == 0)
						room[y][i] = 7;
					else if (room[y][i] == 6)
						break;
				}
				for (int i = y; i < n; i++) {	//아래쪽
					if (room[i][x] == 0)
						room[i][x] = 7;
					else if (room[i][x] == 6)
						break;
				}
			}
			else if (direction == 3) {
				for (int i = x; i < m; i++) {	//오른쪽
					if (room[y][i] == 0)
						room[y][i] = 7;
					else if (room[y][i] == 6)
						break;
				}
				for (int i = y; i < n; i++) {	//아래쪽
					if (room[i][x] == 0)
						room[i][x] = 7;
					else if (room[i][x] == 6)
						break;
				}
				for (int i = x; i >= 0; i--) {	//왼쪽
					if (room[y][i] == 0)
						room[y][i] = 7;
					else if (room[y][i] == 6)
						break;
				}
			}
			else if (direction == 4) {
				for (int i = y; i >= 0; i--) {	//위쪽
					if (room[i][x] == 0)
						room[i][x] = 7;
					else if (room[i][x] == 6)
						break;
				}
				for (int i = y; i < n; i++) {	//아래쪽
					if (room[i][x] == 0)
						room[i][x] = 7;
					else if (room[i][x] == 6)
						break;
				}
				for (int i = x; i >= 0; i--) {	//왼쪽
					if (room[y][i] == 0)
						room[y][i] = 7;
					else if (room[y][i] == 6)
						break;
				}
			}
			break;
		case 3:
			if (direction == 1) {
				for (int i = y; i >= 0; i--) {	//위쪽
					if (room[i][x] == 0)
						room[i][x] = 7;
					else if (room[i][x] == 6)
						break;
				}
				for (int i = x; i >= 0; i--) {	//왼쪽
					if (room[y][i] == 0)
						room[y][i] = 7;
					else if (room[y][i] == 6)
						break;
				}
			}
			else if (direction == 2) {
				for (int i = y; i >= 0; i--) {	//위쪽
					if (room[i][x] == 0)
						room[i][x] = 7;
					else if (room[i][x] == 6)
						break;
				}
				for (int i = x; i < m; i++) {	//오른쪽
					if (room[y][i] == 0)
						room[y][i] = 7;
					else if (room[y][i] == 6)
						break;
				}
			}
			else if (direction == 3) {
				for (int i = x; i < m; i++) {	//오른쪽
					if (room[y][i] == 0)
						room[y][i] = 7;
					else if (room[y][i] == 6)
						break;
				}
				for (int i = y; i < n; i++) {	//아래쪽
					if (room[i][x] == 0)
						room[i][x] = 7;
					else if (room[i][x] == 6)
						break;
				}
			}
			else if (direction == 4) {
				for (int i = y; i < n; i++) {	//아래쪽
					if (room[i][x] == 0)
						room[i][x] = 7;
					else if (room[i][x] == 6)
						break;
				}
				for (int i = x; i >= 0; i--) {	//왼쪽
					if (room[y][i] == 0)
						room[y][i] = 7;
					else if (room[y][i] == 6)
						break;
				}
			
			}
			break;
		case 2:
			if (direction == 1) {
				for (int i = x; i < m; i++) {	//오른쪽
					if (room[y][i] == 0)
						room[y][i] = 7;
					else if (room[y][i] == 6)
						break;
				}
				for (int i = x; i >= 0; i--) {	//왼쪽
					if (room[y][i] == 0)
						room[y][i] = 7;
					else if (room[y][i] == 6)
						break;
				}
			}
			else if (direction == 2) {
				for (int i = y; i >= 0; i--) {	//위쪽
					if (room[i][x] == 0)
						room[i][x] = 7;
					else if (room[i][x] == 6)
						break;
				}
				for (int i = y; i < n; i++) {	//아래쪽
					if (room[i][x] == 0)
						room[i][x] = 7;
					else if (room[i][x] == 6)
						break;
				}
			}
			break;
		case 1:
			if (direction == 1) {
				for (int i = y; i >= 0; i--) {	//위쪽
					if (room[i][x] == 0)
						room[i][x] = 7;
					else if (room[i][x] == 6)
						break;
				}		
			}
			else if (direction == 2) {
				for (int i = x; i < m; i++) {	//오른쪽
					if (room[y][i] == 0)
						room[y][i] = 7;
					else if (room[y][i] == 6)
						break;
				}			
			}
			else if (direction == 3) {
				for (int i = y; i < n; i++) {	//아래쪽
					if (room[i][x] == 0)
						room[i][x] = 7;
					else if (room[i][x] == 6)
						break;
				}
			}
			else if (direction == 4) {
				for (int i = x; i >= 0; i--) {	//왼쪽
					if (room[y][i] == 0)
						room[y][i] = 7;
					else if (room[y][i] == 6)
						break;
				}
			}
			break;
		}
	}
};

class Office {
public:
	int** room;
	int n;
	int m;
	vector<Camera> cameras;
	int* direction;
	int least = 0;
	Office(int y, int x) {
		n = y; m = x;
		Camera ca;
		room = new int* [n];
		for (int i = 0; i < n; i++) {
			room[i] = new int[m];
			for (int j = 0; j < m; j++) {
				cin >> room[i][j];

				if (room[i][j] > 0 && room[i][j] < 6) {
					ca.y = i; ca.x = j; ca.type = room[i][j];
					if (ca.type == 6) {
						ca.watch(room, n, m, 0);
					}
					else {
						cameras.push_back(ca);
					}
				}
			}
		}
		direction = new int[cameras.size()];
		least = n * m;
	}

	void copy_room(int**& copy) {
		copy = new int* [n];
		for (int i = 0; i < n; i++) {
			copy[i] = new int[m];
			for (int j = 0; j < m; j++) {
				copy[i][j] = room[i][j];
			}
		}
	}

	void dfs(int depth) {
		int temp = 0;
		if (depth == cameras.size()) {
			int** copy;
			copy_room(copy);

			for (int i = 0; i < cameras.size(); i++) {
				cameras[i].watch(copy, n, m, direction[i]);
			}
			temp = calc(copy);
			//print(copy);
			if (temp < least)
				least = temp;

			return;
		}

		if (cameras[depth].type == 2) {
			for (int i = 1; i <= 2; i++) {
				direction[depth] = i;
				dfs(depth + 1);
			}
		}
		else {
			for (int i = 1; i <= 4; i++) {
				direction[depth] = i;
				dfs(depth + 1);
			}
		}
	}

	int calc(int **matrix) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == 0)
					cnt++;
			}
		}
		return cnt;
	}

	void print(int **matrix) {
		cout << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << matrix[i][j] << " ";
			}cout << endl;
		}
	}
};

int main() {
	int n, m;

	cin >> n >> m;

	Office office(n, m);

	office.dfs(0);

	cout << office.least;
}