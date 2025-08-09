#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long sum1 = 0, sum2 = 0;
    int limit = 2 * (queue1.size() + queue2.size());

    queue<int> q1, q2;
    
    for(int a : queue1)
    {
        q1.push(a);
        sum1 += a;
    }
    for(int a : queue2)
    {
        q2.push(a);
        sum2 += a;
    }
    
    for(int i = 0; i < limit; i++)
    {
        if(sum1 == sum2)
            break;
        else if(sum1 > sum2)
        {
            q2.push(q1.front());
            sum2 += q1.front();
            sum1 -= q1.front();
            q1.pop();
        }
        else
        {
            q1.push(q2.front());
            sum1 += q2.front();
            sum2 -= q2.front();
            q2.pop();
        }
        
        ++answer;
    }
    
    if(answer == limit)
        answer = -1;
    
    return answer;
}