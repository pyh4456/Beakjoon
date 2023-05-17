#include<iostream>

using namespace std;

void bubble_sort(int list[], int n) {
    int i, j, temp;

    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (list[j] < list[j + 1]) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

int main() {
	int num, average = 0;
	int list[5];
	for (int i = 0; i < 5; i++) {
		cin >> num;
		average += num;
		list[i] = num;
	}

    bubble_sort(list, 5);


	cout << average / 5 << "\n" << list[2];
}