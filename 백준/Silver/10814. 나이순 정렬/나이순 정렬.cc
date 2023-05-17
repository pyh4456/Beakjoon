#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;
#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

void merge(pair<int, string>* data, int start, int mid, int end) {
	pair<int, string>* merged = new pair<int, string>[end - start + 1];

	int i = start, j = mid + 1, count = 0, k = 0;

	while (i <= mid && j <= end) {
		if (data[i].first <= data[j].first) {
			merged[count++] = data[i++];
		}
		else {
			merged[count++] = data[j++];
		}
	}
	while (i <= mid) {
		merged[count++] = data[i++];
	}
	while (j <= end) {
		merged[count++] = data[j++];
	}

	for (int i = 0; i < count; i++) {
		data[i + start] = merged[i];
	}
}

void mergesort(pair<int, string> * data, int start, int end) {
    pair<int, string> temp;

	if(start < end) {
		int mid = (start + end) / 2;
		mergesort(data, start, mid);
		mergesort(data, mid+1, end);
		merge(data, start, mid, end);
	}

}

int main() {
	int n, age;
	string name;
	pair<int, string> *list;

	cin >> n;

	list = new pair<int, string>[n];

	for (int i = 0; i < n; i++) {
		cin >> list[i].first >> list[i].second;
	}

	mergesort(list, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << list[i].first << " " << list[i].second << "\n";
	}
}