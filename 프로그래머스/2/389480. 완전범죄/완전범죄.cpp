#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <functional>
#include <stack>

using namespace std;

struct compare
{
    bool operator()(vector<int> a, vector<int> b)
    {
        if(a[0] == a[1] && b[0] == b[1])
        {
            return a < b;
        }
        
        return static_cast<float>(a[0]) / static_cast<float>(a[1]) <
            static_cast<float>(b[0]) / static_cast<float>(b[1]);
    }
};

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    int aSum = 0, bSum = 0;
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;
    stack<vector<int>> s;
    
    for(auto data : info)
    {
        pq.push(data);
    }
    
    while(!pq.empty())
    {
        cout << pq.top()[0] << " " << pq.top()[1];
        
        if(bSum + pq.top()[1] < m)
        {
            bSum += pq.top()[1];
            cout << " b\n"; 
        }
        else
        {
            aSum += pq.top()[0];
            cout << " a\n";
        }
        
        pq.pop();
    }
    
    answer = aSum; 
    
    if(aSum >= n)
    {
        answer = -1;
    }
    
    return answer;
}