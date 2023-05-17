#include <iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num, product = 1;
	bool isSame = false;
	string str = "";
	vector<string> vector;

	cin >> num;
	vector.push_back(to_string(num % 42));

	while (cin >> num) {
		isSame = false;
		str = to_string(num % 42);

		for (int i = 0; i < vector.size(); i++) {
			if (str == vector[i]) {
				isSame = true;
				break;
			}
		}

		if (!isSame) {
			vector.push_back(str);
		}
	}

	cout << vector.size();
}