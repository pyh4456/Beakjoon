#include <string>
#include <vector>
#include <iostream> 
#include <algorithm>
using namespace std;

int dfs(int i, int j, vector<string> &maps, int **check){
    int cnt = maps[i][j] - 48;
    check[i][j] = true;
    
    if(i > 0){
        if(maps[i - 1][j] != 'X' && !check[i -1 ][j]){
            cnt += dfs(i - 1, j, maps, check);
        }
    }
    if(i < maps.size() - 1){
        if(maps[i + 1][j] != 'X' && !check[i + 1][j]){
            cnt += dfs(i + 1, j, maps, check);
        }
    }
    if(j > 0){
        if(maps[i][j - 1] != 'X' && !check[i][j - 1]){
            cnt += dfs(i, j - 1, maps, check);
        }
    }
    if(j < maps[0].size() - 1){
        if(maps[i][j + 1] != 'X' && !check[i][j + 1]){
            cnt += dfs(i, j + 1, maps, check);
        }
    }
    return cnt;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int **check = new int*[maps.size()];
    for(int i = 0; i < maps.size();i++){
        check[i] = new int[maps[0].size()];
    }
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[0].size(); j++){
            check[i][j] = false;
        }
    }
    
    for(int i = 0; i < maps.size();i++){
        for(int j = 0; j < maps[0].size(); j++){
            cout << maps[i][j];
        }cout <<endl;
    }
    
     for(int i = 0; i < maps.size();i++){
        for(int j = 0; j < maps[0].size(); j++){
            if(maps[i][j] != 'X' && !check[i][j]){
                cout << "E";
                answer.push_back(dfs(i, j, maps, check));
            }
        }
     }
    
    sort(answer.begin(), answer.end());
    if(answer.size() == 0){
        answer.push_back(-1);
    }
    
    return answer;
}