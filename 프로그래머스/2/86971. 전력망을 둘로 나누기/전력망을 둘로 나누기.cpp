#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    int a = 0, b = 0, least = n, temp;
    int indexa, indexb;
    vector<bool> visited_a(n), visited_b(n);
    queue<int> qa, qb;
    
    vector<vector<int>> graph(n);
    
    for(auto wire : wires)
    {
        graph[wire[0] - 1].push_back(wire[1] - 1);
        graph[wire[1] - 1].push_back(wire[0] - 1);
    }
    
    
    for(auto wire : wires)
    {
        a = 0; b = 0;
        
        visited_a[wire[0] - 1] = true;
        visited_b[wire[1] - 1] = true;
        visited_a[wire[1] - 1] = true;
        visited_b[wire[0] - 1] = true;
        
        qa.push(wire[0] - 1);
        qb.push(wire[1] - 1);
        
        while(!qa.empty())
        {
            indexa = qa.front();
            qa.pop();
            a++;
            visited_a[indexa] = true;
            
            for(int edge : graph[indexa])
            {
                if(visited_a[edge])
                    continue;
            
                qa.push(edge);
            }
        }
        
        while(!qb.empty())
        {
            indexb = qb.front();
            qb.pop();
            b++;
            visited_b[indexb] = true;
            
            for(int edge : graph[indexb])
            {
                if(visited_b[edge])
                    continue;
                
                qb.push(edge);
            }
        }
        
        temp = a - b;
        if(temp < 0)
            temp = 0 - temp;
        
        if(temp < least)
            least = temp;
        
        for(int i = 0; i < n; i++)
        {
            visited_a[i] = false;
            visited_b[i] = false;
        }
    }
    
    return least;
}