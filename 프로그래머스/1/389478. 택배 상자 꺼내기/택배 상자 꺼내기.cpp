#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    int x, y;
    vector<int> cnt(w); 
    
    int i = 0;
    while(i < n)
    {
        if((i / w) % 2 == 0)
        {
            cnt[i % w]++;
            
            if(i == num - 1)
            {
                y = i / w;
                x = i % w;
            }
        }
        else
        {
            cnt[(w - 1) - i % w]++;
            
            if(i == num - 1)
            {
                y = i / w;
                x = (w - 1) - i % w;
            }
        }
        
        i++;
    }
    
    for(int i = 0; i < cnt.size(); i++)
    {
        cout << cnt[i] << " ";
    }
    
    answer = cnt[x] - y;
    

    return answer;
}