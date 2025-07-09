#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

bool CanConvert(string a, string b)
{
    int cnt = 0;
    
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == b[i])
            cnt ++;
    }
    return cnt == a.size() - 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool find = false;
    int depth = 0, cnt = 1, next_cnt = 0;
    string a;
    
    queue<string> q;
    set<string> s;
    
    q.push(begin);
    
    while(!q.empty())
    {
        //cout << "depth: " << depth << endl;  
        //cout <<"cnt: " << cnt << endl;

        a = q.front();
        q.pop();   
        cnt--;
        
        //cout << a << endl;
        
        for(int i = 0; i < words.size(); i++)
        {
            if(CanConvert(a, words[i]))
            {                
                if(words[i] == target)
                {
                    find = true;
                    break;
                }
                    
                if(s.find(words[i]) == s.end())
                {
                    next_cnt++;
                    //cout << words[i] << " ";

                    q.push(words[i]);
                    s.insert(words[i]);
                }
            }
        }
        //cout << endl;
        
        if(cnt == 0)
        {
            depth++;
            cnt = next_cnt;
            next_cnt = 0;
        }
        
    }
    
    answer = depth;
    
    if(!find)
        answer = 0;
    
    return answer;
}