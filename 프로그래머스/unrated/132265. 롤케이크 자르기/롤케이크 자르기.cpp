#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    map<int, int> a, b;
    int answer = 0;
    
    for(auto t : topping){
        a[t]++;
    }
    
    for(int i = topping.size() - 1; i >= 0; i--){
        b[topping[i]]++;
        a[topping[i]]--;
        if(a[topping[i]] == 0){
            a.erase(topping[i]);
        }
        if(a.size() == b.size())
            answer++;
    }
    
    
    return answer;
}