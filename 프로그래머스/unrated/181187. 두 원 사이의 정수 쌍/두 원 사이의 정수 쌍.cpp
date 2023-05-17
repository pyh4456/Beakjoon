#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) { //r2 > r1
    long long answer = 0;

    for (int i = 1; i <= r2; i++) {
        answer += floor(sqrt(pow(r2, 2) - pow(i , 2))) + 1;

        if (i < r1) {
            answer -= ceil(sqrt(pow(r1, 2) - pow(i , 2)));
        }
    }

    return answer * 4;
}