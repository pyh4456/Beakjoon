#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<int> elements) 
{
    int answer = 0;
    int subsequence = 0;
    map<int, bool> exist;
    vector<int> v;
    
    v.reserve(elements.size() * 2);
    for(int i = 0; i < elements.size(); i++)
    {
        v.push_back(elements[i]);
    }
    for(int i = 0; i < elements.size(); i++)
    {
        v.push_back(elements[i]);
    }
    
    
  
    for(int i = 0; i < elements.size(); i++)
    {
        subsequence  = 0;
        
        for(int j = 0; j < elements.size(); j++)
        {
            subsequence += v[j + i];
            if(!exist[subsequence])
            {
                answer++;
                exist[subsequence] = true;
            }
        }     
    }

    return answer;
}