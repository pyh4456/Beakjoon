#include <iostream>
#include<string>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	string str = "";
	cin >> num;

	for (int i = 0; i < num; i++) {
		str += " ";
	}

	for (int i = 0; i < num; i++) {
		str[num-i-1] = '*';
		cout << str << "\n";
	}
}