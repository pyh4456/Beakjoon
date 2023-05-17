#include <iostream>
#include<string>
#include<vector>
using namespace std;

struct mystruct{
	char alphabet;
	int used;
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	bool duplicate = false;
	mystruct most_used = { '?',0 };
	string str;
	vector<mystruct> vector;

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		str[i] = toupper(str[i]);
	}
	

	for (int i = 0; i < str.size(); i++) {
		duplicate = false;
		for (int j = 0; j < vector.size(); j++) {
			if (str[i] == vector[j].alphabet) {
				duplicate = true;
				vector[j].used++;
			}
		}
		if (!duplicate) 
			vector.push_back({ str[i], 1 });
	}

	for (int i = 0; i < vector.size(); i++) {
		if (most_used.used < vector[i].used) {
			most_used = vector[i];
		}
	}

	for (int i = 0; i < vector.size(); i++) {
		if (most_used.used == vector[i].used && most_used.alphabet != vector[i].alphabet ) {
			most_used = { '?',0 };
			break;
		}
	}

	cout << most_used.alphabet;
}