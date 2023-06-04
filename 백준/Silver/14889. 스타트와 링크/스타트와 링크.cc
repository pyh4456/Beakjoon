#include <iostream>
#include<limits.h>
#define SWAP(a, b, temp) ((temp) = (a), (a) = (b), (b) = (temp))

using namespace std;

int n, ** matrix, * member, * start, * link;
int least = INT_MAX;

int calc_diff() {
	int st = 0, li = 0;

	for (int i = 0; i < (n / 2) - 1; i++) {
		for (int j = i; j < n / 2; j++) {
			st += matrix[start[i]][start[j]];
			st += matrix[start[j]][start[i]];
		}
	}
	for (int i = 0; i < (n / 2) - 1; i++) {
		for (int j = i; j < n / 2; j++) {
			li += matrix[link[i]][link[j]];
			li += matrix[link[j]][link[i]];
		}
	}
	if (st < li) {
		return li - st;
	}
	else {
		return st - li;
	}
}

void team_up() {
	int start_cnt = 0, link_cnt = 0;

	for (int i = 0; i < n; i++) {
		if (member[i] == start[start_cnt]) {
			start_cnt++;
		}
		else {
			link[link_cnt] = member[i];
			link_cnt++;
		}
	}
}

void combination(int depth, int index) {
	int temp, diff;

	if (depth == n / 2) {
		team_up();
		diff = calc_diff();
		if (diff < least)
			least = diff;

		return;
	}

	for (int i = index; i < n; i++) {
		start[depth] = i;
		combination(depth + 1, i + 1);
	}
}

int main() {
	cin >> n;

	matrix = new int* [n];
	member = new int[n];
	start = new int[n / 2];
	link = new int[n / 2];

	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		member[i] = i;
	}

	combination(0, 0);

	cout << least;
}
