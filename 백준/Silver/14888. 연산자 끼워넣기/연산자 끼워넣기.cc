#include<iostream>
#include<limits.h>
#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

using namespace std;


int n, * a, add, sub, mul, divi;
int* oper;//0: +, 1: -, 2: *, 3: /
int greatest = INT_MIN, least = INT_MAX;

int calc() {
	int out = a[0];

	for (int i = 1; i < n; i++) {
		switch (oper[i - 1]) {
		case 0:
			out += a[i];
			break;
		case 1:
			out -= a[i];
			break;
		case 2:
			out *= a[i];
			break;
		case 3:
			out /= a[i];
			break;
		}
	}
	return out;
}

void print() {
	cout << endl;
	for (int i = 0; i < n - 1; i++)
	{
		cout << oper[i] << " ";
	}cout << endl;
}

void dfs(int depth) {
	int temp;
	int opertemp;
	if (depth == n - 1) {
		temp = calc();
		if (temp > greatest) {
			greatest = temp;
		}
		if (temp < least) {
			least = temp;
		}

		return;
	}

	for (int i = depth; i < n - 1; i++)
	{
		SWAP(oper[depth], oper[i], opertemp);  
		dfs(depth + 1); 
		SWAP(oper[depth], oper[i], opertemp);
	}
}

int main() {

	cin >> n;

	a = new int[n];
	oper = new int[n - 1];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> add;
	cin >> sub;
	cin >> mul;
	cin >> divi;

	for (int i = 0; i < add; i++) {
		oper[i] = 0;
	}
	for (int i = 0; i < sub; i++) {
		oper[i + add] = 1;
	}
	for (int i = 0; i < mul; i++) {
		oper[i + add + sub] = 2;
	}
	for (int i = 0; i < divi; i++) {
		oper[i + add + sub + mul] = 3;
	}

	dfs(0);

	cout << greatest << "\n" << least;
}