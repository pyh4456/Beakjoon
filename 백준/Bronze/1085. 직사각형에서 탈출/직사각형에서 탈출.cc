#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main() {
	int nums[4], least = 1000;

	cin >> nums[0] >> nums[1] >> nums[2] >> nums[3];
	nums[2] -= nums[0];
	nums[3] -= nums[1];
	// x, w - x, y, h - y

	for (int i = 0; i < 4; i++) {
		if (least > nums[i]) {
			least = nums[i];
		}
	}

	cout << least;
}