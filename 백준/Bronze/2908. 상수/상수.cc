#include <iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str, temp;
	int a, b;
	cin >> a >> b;

	str = to_string(a);
	for (int i = str.size() - 1; i >= 0; i--) {
		temp += str[i];
	}
	a = stoi(temp);

	temp = "";

	str = to_string(b);
	for (int i = str.size()-1; i >= 0; i--) {
		temp += str[i];
	}
	b = stoi(temp);

	if (a > b) cout << a;
	else cout << b;
}