#include <iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	char previous_letter = ' ';
	int num_of_word = 0;
	getline(cin, str);

	for (int i = 0; i < str.size(); i++) {
		if (previous_letter == ' ' && str[i] != ' ') {
			num_of_word++;
		}
		previous_letter = str[i];
	}
	cout << num_of_word;
}