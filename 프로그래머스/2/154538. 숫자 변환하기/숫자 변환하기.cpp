#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int bfs(int x, int y, int n){
    queue<int> q;
    set<int> s;
    q.push(x);
    s.insert(x);
    
    int buf, cnt = q.size(), depth = 0;

    while(q.size() > 0){
        while(cnt > 0){
            buf = q.front();
            q.pop();
            
            if(buf == y){
                return depth;
            }
            else if(buf < y){
                if(s.insert(buf + n).second){
                    q.push(buf + n);
                }
                if(s.insert(buf * 2).second){
                    q.push(buf * 2);
                }
                if(s.insert(buf * 3).second){
                    q.push(buf * 3);
                }
                
                
            }
            
            cnt--;
        }
        depth++;
        cnt = q.size();
    }
    
    return -1;
}

int solution(int x, int y, int n) {
    int answer = 0;
    
    return bfs(x, y, n);
}