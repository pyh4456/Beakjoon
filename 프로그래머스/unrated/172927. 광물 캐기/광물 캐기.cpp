#include <string>
#include <vector>
#include <queue>
#include<iostream>
using namespace std;

struct cmp {
  bool operator()(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
  }
};

int fatigue(int pick, string minerals){
    int out = 0;
    switch(pick){
        case 0:
            if(minerals != "")
                return out = 1;
            else
                return out = 0;
            break;
        case 1:
            if(minerals == "diamond")
                return out = 5;
            else if(minerals != "")
                return out = 1;
            else 
                return out = 0;
            break;
        case 2:
            if(minerals == "diamond")
                return out = 25;
            else if(minerals == "iron")
                return out = 5;
            else if(minerals == "stone")
                return out = 1;
            else
                return out = 0;
            break;
    }
    return out;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0, temp = minerals.size();
    int cnt = 0, sum = 0, least = 125, size = (minerals.size() / 5) + 1;
    int *pickaxe;  //곡괭이가 사용되는 순서를 저장할 배열
    int current_pick;   //현재 검사중인 곡괭이
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    
    for(int i = 0; i < 5 * size - temp; i++){    //minerals에 의미없는 값을 넣어서 길이를 5의 배수로 만든다.
        minerals.push_back("");
    }
    temp = picks[0] + picks[1] + picks[2];
    if(size > temp)
        size = temp;
   
    for(int i = 0; i < size; i++){
        temp = 0;
        temp += fatigue(2, minerals[i*5]);
        temp += fatigue(2, minerals[i*5 + 1]);
        temp += fatigue(2, minerals[i*5 + 2]);
        temp += fatigue(2, minerals[i*5 + 3]);
        temp += fatigue(2, minerals[i*5 + 4]);
        pq.push(make_pair(temp, i));
    }
   
    int i;
    while(pq.size() != 0){
        if(picks[0] > 0){
            current_pick = 0;
            picks[0]--;
        }else if(picks[1] > 0){
            current_pick = 1;
            picks[1]--;
        }else{
            current_pick = 2;
        }

        i = pq.top().second;
        answer += fatigue(current_pick, minerals[i*5]);
        answer += fatigue(current_pick, minerals[i*5 + 1]);
        answer += fatigue(current_pick, minerals[i*5 + 2]);
        answer += fatigue(current_pick, minerals[i*5 + 3]);
        answer += fatigue(current_pick, minerals[i*5 + 4]);
        pq.pop();
    }
    
    return answer;
}