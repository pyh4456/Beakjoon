#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

bool compare(int* a, int* b) {
	if (a[0] == b[0]) {
		return a[1] < b[1];
	}
	return a[0] < b[0];
}

int main() {
	int **coordinates;
	int *coordinate;

	int n;

	scanf("%d", &n);
	
	coordinates = new int* [n];

	for (int i = 0; i < n; i++) {
		coordinate = new int[2];
		scanf("%d", &coordinate[0]);
		scanf("%d", &coordinate[1]);
		coordinates[i] = coordinate;
	}

	sort(coordinates, coordinates + n, compare);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", coordinates[i][0], coordinates[i][1]);
	}
}