#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

struct assignment{
    string name;
    int starttime;  //분단위로 변경 ex) 11:40 = 700
    int playtime;   //분단위로 변경
};

struct cmp{
    bool operator()(assignment a, assignment b){
        return a.starttime > b.starttime;
    }  
};

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<assignment> waiting;
    priority_queue<assignment, vector<assignment>, cmp> sorted;
    assignment assign;
    string temp;
    assignment current;
    int time;
    
    for(int i = 0; i < plans.size(); i++){
        time = 0;
        time += (plans[i][1][0] - 48) * 600;
        time += (plans[i][1][1] - 48) * 60;
        time += (plans[i][1][3] - 48) * 10;
        time += (plans[i][1][4] - 48);
        
        assign.name = plans[i][0];
        assign.starttime = time;
        assign.playtime = stoi(plans[i][2]);
        sorted.push(assign);
    }
    
    current = sorted.top();
    time = current.starttime;
    sorted.pop();
    
    while(sorted.size() != 0){
        
        if(time + current.playtime > sorted.top().starttime){   //현재 과제가 도중에 중단될경우
            current.playtime -= (sorted.top().starttime - time);
            waiting.push(current);
            current = sorted.top();
            sorted.pop();
            time = current.starttime;
            
        }else{                  //현재 과제가 완료될경우
            answer.push_back(current.name);
            time += current.playtime;
            
            while(waiting.size() > 0){
                current = waiting.top();
                waiting.pop();
                
                if(time + current.playtime <= sorted.top().starttime){
                    time += current.playtime;
                    answer.push_back(current.name);
                }else{
                    current.playtime -= (sorted.top().starttime - time);
                    waiting.push(current);
                    break;
                }
            }
            current = sorted.top();
            sorted.pop(); 
            time = current.starttime;
        }
    }

    answer.push_back(current.name);
    
    while(waiting.size() != 0){
        answer.push_back(waiting.top().name);
        waiting.pop();
    }
    
    return answer;
}