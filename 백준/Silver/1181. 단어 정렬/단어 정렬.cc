#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}

int main() {
	int n;
	string word, *words, prev = "";

	scanf("%d", &n);

	words = new string[n];

	for (int i = 0; i < n; i++) {
		cin >> word;

		words[i] = word;
	}
	sort(words, words + n, compare);

	for (int i = 0; i < n; i++) {
		if (prev != words[i]) {
			cout << words[i] << "\n";
			prev = words[i];
		}
	}
}