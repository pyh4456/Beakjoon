#include<iostream>

using namespace std;

struct Consulting {
	int days;
	int v;
};

int schedule(int** benefit, Consulting* stuffs, int n, int k) {
	int cnt_w = 0, temp;

	for (int i = 0; i <= n; i++) {
		benefit[i][0] = 0;
	}
	for (int i = 0; i <= k; i++) {
		benefit[0][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int w = 1; w <= k; w++) {
			if (w < stuffs[i - 1].days + i - 1) {
				benefit[i][w] = benefit[i - 1][w];
			}
			else if (w == stuffs[i - 1].days + i - 1) {
				if (benefit[i - 1][w] > stuffs[i - 1].v + benefit[i - 1][w - stuffs[i - 1].days]) {
					benefit[i][w] = benefit[i - 1][w];
				}
				else {
					benefit[i][w] = stuffs[i - 1].v + benefit[i - 1][w - stuffs[i - 1].days];
				}	
			}
			else {
				if (benefit[i][w - 1] < benefit[i - 1][w]) {
					benefit[i][w] = benefit[i - 1][w];
				}
				else {
					benefit[i][w] = benefit[i][w - 1];
				}
			}
		}
	}

	return benefit[n][k];
}

void print(int** benefit, int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cout << benefit[i][j] << " ";
		}cout << endl;
	}
	cout << endl;
}


int main() {
	int n, cnt = 0, greatest = 0;
	int** benefit;
	Consulting* consult;

	cin >> n;

	benefit = new int* [n + 1];
	for (int i = 0; i <= n; i++) {
		benefit[i] = new int[n + 1];
	}
	consult = new Consulting[n];

	for (int i = 0; i < n; i++) {
		cin >> consult[i].days >> consult[i].v;
	}

	cout << schedule(benefit, consult, n, n) <<endl;
}