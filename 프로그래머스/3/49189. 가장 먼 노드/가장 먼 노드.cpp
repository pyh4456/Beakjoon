#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <queue>

using namespace std;




int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> graph(n);
    vector<int> distance(n);
    set<int> arrived;
    queue<int> cursor;
    
    for(auto e: edge)
    {
        graph[e[0] - 1].push_back(e[1]);
        graph[e[1] - 1].push_back(e[0]);
    }
    
    distance[0] = 0;
    arrived.insert(1);
    cursor.push(1);
    int index;
    int dist = 1;
    
    while(!cursor.empty())
    {
        index = cursor.front();
        cursor.pop();
        
        //cout << "at " << index <<endl;
        
        for(int i = 0; i < graph[index - 1].size(); i++)
        {
            int temp = graph[index - 1][i];
            
            if(arrived.find(temp) != arrived.end())
                continue;

            distance[temp - 1] = distance[index - 1] + 1;
            arrived.insert(temp);
            cursor.push(temp);
            //cout << "insert " << temp << " dist : " << distance[index] + 1<<endl;
        }
    }
    
    int greatest = 0;

    for(int i = 0; i < n; i++)
    {
        if(distance[i] > greatest)
            greatest = distance[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        if(distance[i] == greatest)
            answer++;
    }
    
    return answer;
}