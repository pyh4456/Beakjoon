#include <iostream>
using namespace std;

int main() {
	int a, b, v, days = 1;
	cin >> a >> b >> v;

	days = (v - b - 1) / (a - b) + 1;

	cout << days;
}