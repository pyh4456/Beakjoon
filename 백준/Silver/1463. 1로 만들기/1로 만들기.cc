#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int parent[1000001] = { 0 };
int value[1000001] = { 0 };

void memory(int n) {
	int temp;

	for (int i = 2; i <= n; i++) {
		value[i] = value[i - 1] + 1;
		parent[i] = i - 1;

		if (i % 3 == 0) {
			temp = value[i / 3] + 1;
			if (value[i] > temp) {
				value[i] = temp;
				parent[i] = i / 3;
			}
		}
		if (i % 2 == 0) {
			temp = value[i / 2] + 1;
			if (value[i] > temp) {
				value[i] = temp;
				parent[i] = i / 2;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;

	memory(n);

	cout << value[n] << endl;
}