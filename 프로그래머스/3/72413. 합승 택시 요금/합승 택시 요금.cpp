#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

vector<int> dijkstra(vector<vector<int>> matrix, int start)
{
    int size = matrix.size();
    queue<int> wait;
    vector<int> distance(size, INT_MAX);
    distance[start] = 0;
    
    wait.push(start);
    int temp;
    
    while(!wait.empty())
    {
        temp = wait.front();
        wait.pop();
        //cout << "temp: " << temp << endl;
        for(int i = 0; i < size; i++)
        {
            if(matrix[temp][i] != INT_MAX)
            {
                //cout << i << " ";
                if(distance[i] == INT_MAX)
                {
                    distance[i] = distance[temp] + matrix[temp][i];
                    //cout << "infinite "<< distance[i] << endl;
                    wait.push(i);
                }
                else
                {
                    if(distance[i] > distance[temp] + matrix[temp][i])
                    {
                        distance[i] = distance[temp] + matrix[temp][i];
                        wait.push(i);
                    }
                    //cout << distance[i] << endl;
                }
            }
        }
        
        for(int a : distance)
        {
            //cout << a << " ";
        }
        //cout <<endl;
    }
    
    return distance;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector<int> d_a, d_b, d_s;
    
    vector<vector<int>> matrix(n);
    for(int i = 0; i < matrix.size(); i++)
    {
        matrix[i] = vector<int>(n, INT_MAX);
        matrix[i][i] = 0;
    }
    
    for(auto fare : fares)
    {
        matrix[fare[0] - 1][fare[1] - 1] = fare[2];
        matrix[fare[1] - 1][fare[0] - 1] = fare[2];
    }
    
    d_a = dijkstra(matrix, a - 1);
    d_b = dijkstra(matrix, b - 1);
    d_s = dijkstra(matrix, s - 1);

    vector<int> d_sum(matrix.size());
    for(int i = 0; i < matrix.size(); i++)
    {
        d_sum[i] += d_a[i];
        d_sum[i] += d_b[i];
        d_sum[i] += d_s[i];
    }
    
    for(int i = 0; i < matrix.size(); i++)
    {
        cout << d_a[i] << " ";
    }    cout << endl;
    for(int i = 0; i < matrix.size(); i++)
    {
        cout << d_b[i] << " ";
    }    cout << endl;
    for(int i = 0; i < matrix.size(); i++)
    {
        cout << d_s[i] << " ";
    }    cout << endl;
    
    
    int least = INT_MAX;
    for(int i = 0; i < d_sum.size(); i++)
    {
        if(d_sum[i] < least)
        {
            least = d_sum[i];
        }
    }
    
    return least;
}