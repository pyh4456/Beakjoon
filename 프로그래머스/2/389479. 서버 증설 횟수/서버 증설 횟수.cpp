#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int borrow = 0;
    queue<vector<int>> q; //개수 반납시간
    int presentServer = 0;
    for(int time = 0; time < 24; time++)
    {
        if(!q.empty())
        {
            if(q.front()[0] == time)
            {
                presentServer -= q.front()[1];
                q.pop();
            }
        }
                
        if(players[time] >= presentServer * m)
        {
            borrow = players[time] / m - presentServer;
            //cout << time << " " << borrow << endl;
            
            q.push({ time + k, borrow });
            presentServer += borrow;
            answer += borrow;
        }
    }
    
    
    
    return answer;
}