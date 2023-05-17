#include <iostream>
#include<string>
#include<set>
using namespace std;

int d(int num);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	set<int> set;

	for (int i = 1; i <= 10000; i++) {
		set.insert(d(i));
	}

	for (int i = 1; i <= 10000; i++) {
		if (set.find(i) == set.end()) {
			cout << i << "\n";
		}
	}
}

int d(int num) {
	string str = to_string(num);

	for (int i = 0; i < str.size(); i++) {
		num += str[i] - '0';
	}
	return num;
}