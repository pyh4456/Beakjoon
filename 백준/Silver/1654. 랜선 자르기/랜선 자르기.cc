#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<limits.h>

using namespace std;

int main() {
	long long k, n, * lines, length = 0, cnt = 0, interval, greatest = 0;

	cin >> k >> n;
	lines = new long long[k];

	for (int i = 0; i < k; i++) {
		cin >> lines[i];
		if (greatest < lines[i]) greatest = lines[i];
	}
	length = greatest;
	interval = greatest;

	while (interval > 1) {
		cnt = 0;
		interval = interval / 2;
		for (int i = 0; i < k; i++) {
			cnt += lines[i] / length;
		}
		if (cnt >= n) {
			length += interval;
		}
		else {
			length -= interval;
		}
	}

	if (cnt >= n) {
		while (1) {
			cnt = 0;
			for (int i = 0; i < k; i++) {
				cnt += lines[i] / length;
			}
			if (cnt < n) {
				length--;
				break;
			}
			length++;
		}
	}
	else {
		while (1) {
			cnt = 0;
			for (int i = 0; i < k; i++) {
				cnt += lines[i] / length;
			}
			if (cnt >= n) {
				break;
			}
			length--;
		}
	}

	

	cout << length;
}