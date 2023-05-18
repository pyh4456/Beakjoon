#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int parent[1000001] = { 0 };	// n을 1로 만들기위한 과정의 첫단계의 수를 나타낸다.
int value[1000001] = { 0 };	// value[n] : n을 1로 만들기 위한 횟수

void memory(int n) {	//2부터 n까지의 모든 수에 대해, 1로 만들기 위한 횟수를 value에 저장.
	int temp;

	for (int i = 2; i <= n; i++) {
		// n에서 1을 빼본다.
		value[i] = value[i - 1] + 1;
		parent[i] = i - 1;

		if (i % 3 == 0) {
			//n을 3으로 나눠본다.
			temp = value[i / 3] + 1;
			if (value[i] > temp) {
				value[i] = temp;
				parent[i] = i / 3;
 			}
		}
		if (i % 2 == 0) {
			//n을 2로 나눠본다.
			temp = value[i / 2] + 1;
			if (value[i] > temp) {
				value[i] = temp;
				parent[i] = i / 2;
			}
		}
	}
}

void print_sequense(int n) {	//n을 1로 만들기위한 과정을 보여준다.
	while (n != 1) {
		printf("%d ", n);
		n = parent[n];
	}
	cout << 1;
}

int main() {
	int n;
	cin >> n;
	
	memory(n);

	cout << value[n] << endl;
	print_sequense(n);
}
