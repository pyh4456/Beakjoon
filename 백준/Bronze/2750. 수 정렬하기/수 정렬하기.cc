#include<iostream>
#include<vector>

using namespace std;
#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

void mod_quick_sort(vector<int>& data, int start, int end) {
    int temp;

    if (start >= end) {
        return;
    }
    int pivot = rand() % (end - start) + start; //choose pivot randomly
    SWAP(data[start], data[pivot], temp);   //swap pivot with first element

    pivot = start;
    int i = pivot + 1;
    int j = end;
    temp;
    while (i <= j) {
        while (i <= end && data[i] <= data[pivot]) {
            i++;
        }
        while (j > start && data[j] >= data[pivot]) {
            j--;
        }
        if (i > j) {
            SWAP(data[j], data[pivot], temp);
        }
        else {
            SWAP(data[i], data[j], temp);
        }
    }
    mod_quick_sort(data, start, j - 1);
    mod_quick_sort(data, j + 1, end);
}

int main(int argc, char* argv[]) {
    int n, num;
    vector<int> list;
    vector<int>::iterator iter;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        list.push_back(num);
    }

    mod_quick_sort(list, 0, list.size() - 1);

    for (iter = list.begin(); iter != list.end(); iter++) {
        cout << *iter << endl;
    }
}