#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) { 
    return a > b; 
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    set<int> size;
    map<int, int> count;
    vector<int> vect;
    
    for(int i = 0; i < tangerine.size(); i++){
        size.insert(tangerine[i]);
        count[tangerine[i]]++;
    }
    
    for(set<int>::iterator iter = size.begin(); iter != size.end(); iter++){
        vect.push_back(count[*iter]);
    }
    
    sort(vect.begin(), vect.end(), cmp);
    
     for(int i = 0; i < vect.size(); i++){
        answer++;
        k = k - vect[i];
        if(k <= 0)
        break;
    }
    
    return answer;
}