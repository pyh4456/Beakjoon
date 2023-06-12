#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

inline bool compare(vector<int> a, vector<int> b){
    if(a[1] == b[1]){
        return a[0] < b[0];
    }
    
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int location = -1;
    sort(targets.begin(), targets.end(), compare);
    
    for(int i = 0; i < targets.size(); i++){
        if(location < targets[i][0]){
            answer++;
            location = targets[i][1] - 1;
        }
    }
    
    return answer;
}