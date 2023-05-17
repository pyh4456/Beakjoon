#include <iostream>
#include<string>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	cin >> num;

	for (int i = num; i > 0; i--) {
		cout << i << "\n";
	}
}