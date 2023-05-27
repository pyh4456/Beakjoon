#include<iostream>
#include<bitset>

using namespace std;

#define P 1000000007ll

long long factorial(int n) {
	long long out = 1;
	for (long long i = 1; i <= n; i++) {
		out *= i;
		out %= P;
	}

	return out;
}

long long power(long long n, long long k) {
	if (k == 0) 
		return 1;
	if (k % 2 > 0) 
		return (power(n, k - 1) * n) % P;

	long long half = power(n, k / 2) % P;

	return (half * half) % P;
}

int main() {//n!%MOD * (k!(n-k)!)^(MOD - 2)%MOD
	int n, k;
	long long a, b;
	long long b2;

	cin >> n >> k;

	a = factorial(n);
 	b = factorial(k);
	b = (b * factorial(n - k)) % P;

	b2 = power(b, P - 2);

	cout << (a * b2) % P;
}