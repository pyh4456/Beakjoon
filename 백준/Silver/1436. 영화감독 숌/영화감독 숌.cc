#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int n, cnt = 0, num = 665, cnt2 = 0;
	string str;

	cin >> n;

	while (n > cnt) {
		num++;
		cnt2 = 0;
		str = to_string(num);

		cnt2 = str.find("666");

		if (cnt2 != string::npos) {
			cnt++;
		}

	}
	cout << num;
}