#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int cnt = 0, sum = 0;
    queue<int> q;
    int s[10] = { 0 };
    
    for(int i = 0; i < priorities.size(); i++)
    {
        s[priorities[i]]++;
        q.push(i);
    }
    
    for(int i = 0; i < 10; i++)
    {
        //cout << s[i] << " ";
    } cout << endl;
    
    sum = 0;
    int head;
    
    while(!q.empty())
    {
        sum = 0;

        head = q.front();
        //cout << head;//////////////////
        for(int i = 9; i > priorities[head]; i--)
        {
            sum += s[i];;
        }
        //cout << "  sum : " << sum << endl;////////////
        if(sum == 0)
        {
            cnt++;
            s[priorities[head]]--;
            
            if(head == location)
            {
                answer = cnt;
                break;
            }
        }
        else
        {
            q.push(head);
        }
        
        q.pop();
    }
    
        
    return answer;
}