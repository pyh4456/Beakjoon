#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long memoi[2001] = { 0 };

long long memoization(int num) {
    long long out = 0;
    if (memoi[num] != 0) {
        return memoi[num];
    }
    else {
        out += memoization(num - 1);  //먼저 1칸을 뛰었을때, num - 1의 결과만큼
        out += memoization(num - 2);  //먼저 2칸을 뛰었을때, num - 2의 결과만큼
        memoi[num] = out % 1234567;
        return out;
    }
}

long long solution(int n) {
    long long answer = 0;

    memoi[1] = 1;
    memoi[2] = 2;
    memoi[3] = 3;

    answer = memoization(n);

    return answer % 1234567;
}