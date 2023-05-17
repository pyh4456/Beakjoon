#include <iostream>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	int time = 0;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] <= 67) time += 3;
		else if (str[i] <= 70) time += 4;
		else if (str[i] <= 73) time += 5;
		else if (str[i] <= 76) time += 6;
		else if (str[i] <= 79) time += 7;
		else if (str[i] <= 83) time += 8;
		else if (str[i] <= 86) time += 9;
		else if (str[i] <= 90) time += 10;
	}

	cout << time;
}