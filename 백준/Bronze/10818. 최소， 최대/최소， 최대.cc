#include <iostream>
#include<string>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int size, least, maximum, num;

	cin >> size;

	cin >> num;
	least = num; maximum = num;

	for (int i = 0; i < size - 1; i++) {
		cin >> num;
		if (num < least) least = num;
		if (num > maximum) maximum = num;
	}
	cout << least << " " << maximum;
}