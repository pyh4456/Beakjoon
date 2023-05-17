#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main() {
	int n, cnt = 0;
	string str, out;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		cnt = 0;
		out = "NO\n";
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '(') {
				cnt++;
			}
			else if (str[j] == ')') {
				if (cnt > 0) {
					cnt--;
				}
				else {
					break;
				}
			}
			if (j == str.length() - 1 && cnt == 0) {
				out = "YES\n";
			}
		}
		cout << out;
	}
}

