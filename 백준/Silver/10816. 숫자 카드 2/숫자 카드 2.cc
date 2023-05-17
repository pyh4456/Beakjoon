#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int cnt[20000001];

int main() {

	int n, m, num;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		cnt[num + 10000000]++;
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		scanf("%d", &num);
		printf("%d ", cnt[num + 10000000]);
	}
}