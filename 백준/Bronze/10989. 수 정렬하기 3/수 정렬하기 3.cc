#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

int countarray[10001];

int main() {
	int n, num;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		countarray[num]++;
	}

	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < countarray[i]; j++) {
			printf("%d\n", i);
		}
	}
}