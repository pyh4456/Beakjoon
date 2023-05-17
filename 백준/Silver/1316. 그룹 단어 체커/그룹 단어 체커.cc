#include <iostream>
#include<string>
#include<set>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	char previous = 0;
	int num_of_word, num_of_group_word = 0;
	bool is_group_word;
	set<char> set;

	cin >> num_of_word;

	for (int i = 0; i < num_of_word; i++) {
		cin >> str;
		is_group_word = true;

		previous = str[0];
		for (int j = 1; j < str.size(); j++) {
			if (set.find(str[j]) != set.end()) {
				is_group_word = false;
				break;
			}

			if (str[j] != previous) {
				set.insert(previous);
			}

			previous = str[j];
		}
		if (is_group_word) num_of_group_word++;
		set.clear();
	}

	cout << num_of_group_word;
}