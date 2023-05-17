#include <iostream>
#include<string>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num, original, cycle = 0;

	cin >> original;
	num = original;
	while(true){
		num = 10 * (num % 10) + (num / 10 + num % 10) % 10;

		cycle++;
		if (num == original) break;
	}
	cout << cycle;
}