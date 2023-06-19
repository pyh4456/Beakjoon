#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int t = 0;
int **check;

queue<pair<int,int>> wait;

bool bfs(int y, int x, int target_y, int target_x, vector<string> &maps){
    int dy, dx, tempx, tempy;
    int cnt = 0;
    int size = 0;
   
    while(wait.size() != 0){
        wait.pop();
    }
    
    wait.push(make_pair(y, x));
    check[y][x] = true;
    
    while(!wait.empty()){
        size = wait.size();
            
        for(int i = 0; i < size; i++){
            tempy = wait.front().first;
            tempx = wait.front().second;
            
            if(tempy == target_y && tempx == target_x){
                t = cnt;
                return true;
            }     
            wait.pop();
            
            
            //UP
            dy = tempy - 1;
            dx = tempx;
            if(dy >= 0 && !check[dy][dx] && maps[dy][dx] != 'X'){
                wait.push(make_pair(dy, dx));
                check[dy][dx] = true;
            }
            //RIGHT
            dy = tempy;
            dx = tempx + 1;
            if(dx < maps[0].size() && !check[dy][dx] && maps[dy][dx] != 'X'){
                wait.push(make_pair(dy, dx));
                check[dy][dx] = true;
            }
            //DOWN
            dy = tempy + 1;
            dx = tempx;
            if(dy < maps.size() && !check[dy][dx] && maps[dy][dx] != 'X'){
                wait.push(make_pair(dy, dx));
                check[dy][dx] = true;
            }
            //LEFT
            dy = tempy;
            dx = tempx - 1;
            if(dx >= 0 && !check[dy][dx] && maps[dy][dx] != 'X'){
                wait.push(make_pair(dy, dx));
                check[dy][dx] = true;
            }

        }
        cnt++;
    }
    
    return false;
}

int solution(vector<string> maps) {
    int answer = 0;
    int start_x, start_y, lever_x, lever_y, exit_x, exit_y;
    
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[0].size(); j++){
            if(maps[i][j] == 'S'){
                start_y = i; start_x = j;
            }
            if(maps[i][j] == 'E'){
                exit_y = i; exit_x = j;
            }
            if(maps[i][j] == 'L'){
                lever_y = i; lever_x = j;
            }
        }
    }
    
    t = 0;
    check = new int*[maps.size()];
    for(int i = 0; i < maps.size(); i++){
        check[i] = new int[maps[0].size()];
        for(int j = 0; j < maps[0].size(); j++){
            check[i][j] = false;
        }
    }
    if(bfs(start_y, start_x, lever_y, lever_x, maps)){
        answer += t;   

        for(int i = 0; i < maps.size(); i++){
            for(int j = 0; j < maps[0].size(); j++){
                check[i][j] = false;
            }
        }
        if(bfs(lever_y, lever_x, exit_y, exit_x, maps)){
            answer += t;
        }else{
            answer = -1;
        }
    }else{
        answer = -1;
    }
    
    return answer;
}