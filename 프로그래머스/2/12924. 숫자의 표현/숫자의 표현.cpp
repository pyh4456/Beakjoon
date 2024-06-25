#include <string>
#include <vector>
#include <iostream>


using namespace std;

int solution(int n) {
    int answer = 1;
    int cnt = 1, big = 1, small = 1;
    int sum = 0;
    
    while(cnt <= n)
    {
        //cout << "cnt : " << cnt <<"  , sum : " << sum << endl; 
        
        if(sum > n)
        {
            sum -= small++;
            continue;
        }
        else if(sum == n)
        {
            answer++;
        }
        
        sum += cnt++;
    }
    
    return answer;
}