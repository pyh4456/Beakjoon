#include <iostream>
#include<string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int test_case, num;
	string str, out;

	cin >> test_case;

	for (int k = 0; k < test_case; k++) {
		out = "";
		cin >> num >> str;

		for (int i = 0; i < str.size(); i++) {
			for (int j = 0; j < num; j++) {
				out += str[i];
			}
		}

		cout << out << "\n";
	}
}