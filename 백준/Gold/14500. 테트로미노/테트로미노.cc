#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>

using namespace std;

//1자 모양(세로) : 1개 가지
int tetrominoI1[4][2] = { {0,0}, {1,0}, {2,0}, {3,0} };
//1자 모양(가로) : 1개 가지
int tetrominoI2[4][2] = { {0,0}, {0,1}, {0,2}, {0,3} };

//네모모양 : 1개 가지
int tetrominoSquare[4][2] = { {0,0}, {0,1}, {1,1}, {1,0} };


//L자 모양(세로) : 4개 가지
int tetrominoL1[4][4][2] = { { {0,0}, {1,0}, {2,0}, {2,1} },
							 { {0,1}, {1,1}, {2,1}, {2,0} },
							 { {0,0}, {0,1}, {1,0}, {2,0} },
							 { {0,0}, {0,1}, {1,1}, {2,1} } };
//L자 모양(가로) : 4개 가지
int tetrominoL2[4][4][2] = { { {0,0}, {0,1}, {0,2}, {1,0} },
							 { {0,0}, {1,0}, {1,1}, {1,2} },
							 { {0,0}, {0,1}, {0,2}, {1,2} },
							 { {1,0}, {1,1}, {1,2}, {0,2} } };


//번개모양(세로) : 2개 가지
int tetrominoLightning1[2][4][2] = { { {0,0}, {1,0}, {1,1}, {2,1} },
									 { {0,1}, {1,0}, {1,1}, {2,0} } };
//번개모양(가로) : 2개 가지
int tetrominoLightning2[2][4][2] = { { {0,0}, {0,1}, {1,1}, {1,2} },
									 { {1,0}, {1,1}, {0,1}, {0,2} } };


//ㅗ모양(세로)   : 2개 가지
int tetrominoH1[2][4][2] = { { {0,0}, {1,0}, {2,0}, {1,1} },
							 { {0,1}, {1,1}, {2,1}, {1,0} } };
//ㅗ모양(가로)   : 2개 가지
int tetrominoH2[2][4][2] = { { {0,0}, {0,1}, {0,2}, {1,1} },
							 { {1,0}, {1,1}, {1,2}, {0,1} } };

int limit[9][2] = { {3,0}, {0,3}, {2,2}, {2,1}, {1,2}, {2,1}, {1,2}, {2,1}, {1,2} };

int main() {
	int** paper, n, m, greatest = 0, temp;

	cin >> n >> m;
	paper = new int* [n];

	for (int i = 0; i < n; i++) {
		paper[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}

	//1자 모양(세로) : 1개 가지
	for (int i = 0; i < n - limit[0][0]; i++) {
		for (int j = 0; j < m - limit[0][1]; j++) {
			temp = 0;
			for (int k = 0; k < 4; k++) {
				temp += paper[i + tetrominoI1[k][0]][j + tetrominoI1[k][1]];
			}
			if (greatest < temp)
				greatest = temp;
		}
	}
	//1자 모양(가로) : 1개 가지
	for (int i = 0; i < n - limit[1][0]; i++) {
		for (int j = 0; j < m - limit[1][1]; j++) {
			temp = 0;
			for (int k = 0; k < 4; k++) {
				temp += paper[i + tetrominoI2[k][0]][j + tetrominoI2[k][1]];
			}
			if (greatest < temp)
				greatest = temp;
		}
	}
	//네모모양 : 1개 가지
	for (int i = 0; i < n - limit[2][0]; i++) {
		for (int j = 0; j < m - limit[2][1]; j++) {
			temp = 0;
			for (int k = 0; k < 4; k++) {
				temp += paper[i + tetrominoSquare[k][0]][j + tetrominoSquare[k][1]];
			}
			if (greatest < temp)
				greatest = temp;
		}
	}
	//L자 모양(세로) : 4개 가지
	for (int i = 0; i < n - limit[3][0]; i++) {
		for (int j = 0; j < m - limit[3][1]; j++) {
			temp = 0;
			for (int k = 0; k < 4; k++) {
				temp += paper[i + tetrominoL1[0][k][0]][j + tetrominoL1[0][k][1]];
			}
			if (greatest < temp)
				greatest = temp;
		}
	}
	for (int i = 0; i < n - limit[3][0]; i++) {
		for (int j = 0; j < m - limit[3][1]; j++) {
			temp = 0;
			for (int k = 0; k < 4; k++) {
				temp += paper[i + tetrominoL1[1][k][0]][j + tetrominoL1[1][k][1]];
			}
			if (greatest < temp)
				greatest = temp;
		}
	}
	for (int i = 0; i < n - limit[3][0]; i++) {
		for (int j = 0; j < m - limit[3][1]; j++) {
			temp = 0;
			for (int k = 0; k < 4; k++) {
				temp += paper[i + tetrominoL1[2][k][0]][j + tetrominoL1[2][k][1]];
			}
			if (greatest < temp)
				greatest = temp;
		}
	}
	for (int i = 0; i < n - limit[3][0]; i++) {
		for (int j = 0; j < m - limit[3][1]; j++) {
			temp = 0;
			for (int k = 0; k < 4; k++) {
				temp += paper[i + tetrominoL1[3][k][0]][j + tetrominoL1[3][k][1]];
			}
			if (greatest < temp)
				greatest = temp;
		}
	}

	//L자 모양(가로) : 4개 가지
	for (int i = 0; i < n - limit[4][0]; i++) {
		for (int j = 0; j < m - limit[4][1]; j++) {
			temp = 0;
			for (int k = 0; k < 4; k++) {
				temp += paper[i + tetrominoL2[0][k][0]][j + tetrominoL2[0][k][1]];
			}
			if (greatest < temp)
				greatest = temp;
		}
	}
	for (int i = 0; i < n - limit[4][0]; i++) {
		for (int j = 0; j < m - limit[4][1]; j++) {
			temp = 0;
			for (int k = 0; k < 4; k++) {
				temp += paper[i + tetrominoL2[1][k][0]][j + tetrominoL2[1][k][1]];
			}
			if (greatest < temp)
				greatest = temp;
		}
	}
	for (int i = 0; i < n - limit[4][0]; i++) {
		for (int j = 0; j < m - limit[4][1]; j++) {
			temp = 0;
			for (int k = 0; k < 4; k++) {
				temp += paper[i + tetrominoL2[2][k][0]][j + tetrominoL2[2][k][1]];
			}
			if (greatest < temp)
				greatest = temp;
		}
	}
	for (int i = 0; i < n - limit[4][0]; i++) {
		for (int j = 0; j < m - limit[4][1]; j++) {
			temp = 0;
			for (int k = 0; k < 4; k++) {
				temp += paper[i + tetrominoL2[3][k][0]][j + tetrominoL2[3][k][1]];
			}
			if (greatest < temp)
				greatest = temp;
		}
	}

	//번개모양(세로) : 2개 가지
	for (int i = 0; i < n - limit[5][0]; i++) {
		for (int j = 0; j < m - limit[5][1]; j++) {
			temp = 0;
			for (int k = 0; k < 4; k++) {
				temp += paper[i + tetrominoLightning1[0][k][0]][j + tetrominoLightning1[0][k][1]];
			}
			if (greatest < temp)
				greatest = temp;
		}
	}
	for (int i = 0; i < n - limit[5][0]; i++) {
		for (int j = 0; j < m - limit[5][1]; j++) {
			temp = 0;
			for (int k = 0; k < 4; k++) {
				temp += paper[i + tetrominoLightning1[1][k][0]][j + tetrominoLightning1[1][k][1]];
			}
			if (greatest < temp)
				greatest = temp;
		}
	}
	//번개모양(가로) : 2개 가지
	for (int i = 0; i < n - limit[6][0]; i++) {
		for (int j = 0; j < m - limit[6][1]; j++) {
			temp = 0;
			for (int k = 0; k < 4; k++) {
				temp += paper[i + tetrominoLightning2[0][k][0]][j + tetrominoLightning2[0][k][1]];
			}
			if (greatest < temp)
				greatest = temp;
		}
	}
	for (int i = 0; i < n - limit[6][0]; i++) {
		for (int j = 0; j < m - limit[6][1]; j++) {
			temp = 0;
			for (int k = 0; k < 4; k++) {
				temp += paper[i + tetrominoLightning2[1][k][0]][j + tetrominoLightning2[1][k][1]];
			}
			if (greatest < temp)
				greatest = temp;
		}
	}
	//ㅗ모양(세로)   : 2개 가지
	for (int i = 0; i < n - limit[7][0]; i++) {
		for (int j = 0; j < m - limit[7][1]; j++) {
			temp = 0;
			for (int k = 0; k < 4; k++) {
				temp += paper[i + tetrominoH1[0][k][0]][j + tetrominoH1[0][k][1]];
			}
			if (greatest < temp)
				greatest = temp;
		}
	}
	for (int i = 0; i < n - limit[7][0]; i++) {
		for (int j = 0; j < m - limit[7][1]; j++) {
			temp = 0;
			for (int k = 0; k < 4; k++) {
				temp += paper[i + tetrominoH1[1][k][0]][j + tetrominoH1[1][k][1]];
			}
			if (greatest < temp)
				greatest = temp;
		}
	}
	//ㅗ모양(가로)   : 2개 가지
	for (int i = 0; i < n - limit[8][0]; i++) {
		for (int j = 0; j < m - limit[8][1]; j++) {
			temp = 0;
			for (int k = 0; k < 4; k++) {
				temp += paper[i + tetrominoH2[0][k][0]][j + tetrominoH2[0][k][1]];
			}
			if (greatest < temp)
				greatest = temp;
		}
	}
	for (int i = 0; i < n - limit[8][0]; i++) {
		for (int j = 0; j < m - limit[8][1]; j++) {
			temp = 0;
			for (int k = 0; k < 4; k++) {
				temp += paper[i + tetrominoH2[1][k][0]][j + tetrominoH2[1][k][1]];
			}
			if (greatest < temp)
				greatest = temp;
		}
	}
	cout << greatest;
}