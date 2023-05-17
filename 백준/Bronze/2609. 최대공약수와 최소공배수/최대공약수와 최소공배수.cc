#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	else
		return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main() {
	int a, b;

	cin >> a >> b;

	cout << gcd(a, b) << "\n" << lcm(a, b);
}