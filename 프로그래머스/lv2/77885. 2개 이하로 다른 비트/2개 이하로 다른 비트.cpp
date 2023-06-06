#include <string>
#include <vector>
#include<iostream>
#include<bitset>
using namespace std;

long long findnum(long long n) {
    bitset<64> set = n;
    int biggest = 0;
    bool yes = false;

    for (int i = 0; i < 64; i++) {
        if (set[i] == 0) {
            set[i] = 1;
            
            if(i != 0){
                set[i - 1] = 0;
            }
            break;
        }
    }
    return set.to_ullong();
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    long long temp;

    for (int i = 0; i < numbers.size(); i++) {
        temp = findnum(numbers[i]);

        answer.push_back(temp);
    }

    return answer;
}