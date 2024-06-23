#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    vector<vector<int>> graph(n);
    
    for(auto road : roads)
    {
        graph[road[0] - 1].push_back(road[1] - 1);
        graph[road[1] - 1].push_back(road[0] - 1);
    }
    
    
    queue<int> q;
    q.push(destination - 1);
    set<int> arrived, source;
    vector<int> distance(n, -1);
    int current_node;
    
    distance[destination - 1] = 0;
    
    for(auto num : sources)
    {
        source.insert(num - 1);
    }
    arrived.insert(destination - 1);
    
 
    
    while(!q.empty())
    {
        current_node = q.front();
        q.pop();

        for(auto node : graph[current_node])
        {
            if(arrived.find(node) != arrived.end())
                continue;
            
            distance[node] = distance[current_node] + 1;
            arrived.insert(node);
            q.push(node);
        } 
    }
    
    for(int source : sources)
    {
        answer.push_back(distance[source - 1]);
    }
    
    
    return answer;
}