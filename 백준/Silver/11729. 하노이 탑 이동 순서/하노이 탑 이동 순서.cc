#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
using namespace std;

list<int*> out;
list<int*>::iterator iter;
int cnt = 0;

void ha_noi(int n, int from, int by, int to) {
	cnt++;
	int* temp = new int[2];
		temp[0] = from; temp[1] = to;
	if (n == 1) {
		out.push_back(temp);
	}
	else {
		ha_noi(n - 1, from, to, by);
		out.push_back(temp);
		ha_noi(n - 1, by, from, to);
	}
}

int main() {
	int n;

	cin >> n;
	ha_noi(n, 1, 2, 3);

	printf("%d\n", cnt);

	for (iter = out.begin(); iter != out.end(); iter++) {
		printf("%d %d\n", (* iter)[0], (*iter)[1]);
	}
	
}