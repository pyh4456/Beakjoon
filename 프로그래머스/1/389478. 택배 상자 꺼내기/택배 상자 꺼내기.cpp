#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
   
    vector<vector<int>> v;
    vector<int> temp(w, 0);
    
    int height = n / w;
    if(n % w > 0)
        ++height;
    
    for(int i = 0; i < height; i++)
    {
        v.push_back(temp);
    }
    
    for(int i = 0; i < n; i++)
    {   
        if((i / w) % 2 == 0)
        {
            v[i / w][i % w] = 1;
        }
        else
        {
            v[i / w][w - 1 - i % w] = 1;
        }
    }
    
    for(int i = num / w ; i < height; i++)
    {
        if(v[i][num % w] == 0)
            break;
        
        ++answer;
    }
    
    if(num % w == 0)
        ++answer;
    
    return answer;
}