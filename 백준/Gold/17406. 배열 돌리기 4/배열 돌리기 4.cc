#include<iostream>
#include<limits.h>

using namespace std;

int** arr, **arr_copy, least = INT_MAX, n, m;

void copyarr(int **&input, int **&copy,int n,int m) {	//copy array
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copy[i][j] = input[i][j];
		}
	}
}

void rotate(int **&a, int r, int c, int s) {	//rotate array
	int prev, temp;

	if (s == 0) {//옮겨야 하는 사각형이 크기가 하나일때.
		return;
	}

	//먼저 정사각형의 가장 바깥쪽을 옮긴다.
	//정사각형의 가장 위쪽 줄을 한칸씩 오른쪽으로
	prev = a[r - s - 1][c - s - 1];
	a[r - s - 1][c - s - 1] = a[r - s][c - s -1];
	for (int i = c - s; i <= c + s - 1; i++) {
		temp = a[r - s - 1][i];
		a[r - s - 1][i] = prev;
		prev = temp;
	}

	//정사각형의 가장 오른쪽을 한칸씩 아래쪽으로
	for (int i = r - s; i <= r + s - 1; i++) {
		temp = a[i][c + s - 1];
		a[i][c + s - 1] = prev;
		prev = temp;
	}

	//정사각형의 가장 아래줄을 한칸씩 왼쪽으로
	for (int i = c + s - 2; i >= c - s - 1; i--) {
		temp = a[r + s - 1][i];
		a[r + s - 1][i] = prev;
		prev = temp;
	}

	//정사각형의 가장 왼쪽줄을 한칸씩 위쪽으로
	for (int i = r + s - 2; i >= r - s - 1; i--) {
		temp = a[i][c - s - 1];
		a[i][c - s - 1] = prev;
		prev = temp;
	}

	//옮긴 사각형의 안쪽 사각형을 처리.
	rotate(a, r, c, s - 1);
}

int find_least(int**& a, int n, int m) {	//find least value in the array
	int out = 0, temp = 0;

	for (int i = 0; i < m; i++) {
		out += a[0][i];
	}

	for (int i = 0; i < n; i++) {
		temp = 0;
		for (int j = 0; j < m; j++) {
			temp += a[i][j];
		}
		if (out > temp) {
			out = temp;
		}
	}
	return out;
}

void print(int** a, int n, int m) {	//print array (for test)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int order[6];
bool check[6];

void dfs(int **data, int cnt, int k) {
	int temp, * temparr = new int[3];

	if (cnt == k) {
		copyarr(arr, arr_copy, n, m);

		for (int i = 0; i < k; i++)
		{
			rotate(arr_copy, data[order[i]][0], data[order[i]][1], data[order[i]][2]);

		}
		temp = find_least(arr_copy, n, m);

		if (temp < least)
			least = temp;

		return;
	}

	for (int i = 0; i < k; i++) {
		if (check[i] == true)
			continue;
		check[i] = true;
		order[cnt] = i;
		dfs(data, cnt + 1, k);
		check[i] = false;
	}
}

int main() {
	int k, r, c, s;
	int** rotation;

	cin >> n >> m >> k;

	rotation = new int* [k];
	arr = new int* [n];
	arr_copy = new int* [n];

	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
		arr_copy[i] = new int [m];

		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		rotation[i] = new int[3];
		cin >> rotation[i][0] >> rotation[i][1] >> rotation[i][2];
	}

	dfs(rotation, 0, k);

	cout << least;
}