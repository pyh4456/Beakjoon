#include <iostream>
#include<string>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int maximum, order, count = 0, num;

	cin >> num;
	maximum = num;
	count++;
	order = count;
	
	while (cin >> num) {
		count++;
		if (num > maximum) {
			maximum = num;
			order = count;
		}
	}

	cout << maximum << "\n" << order;
}