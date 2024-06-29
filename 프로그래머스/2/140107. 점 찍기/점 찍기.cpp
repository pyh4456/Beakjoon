#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long x = 0, y = 0, d2 = (long long)d * (long long)d;
    
    //x^2 = d^2 - y^2
   
    while(y <= d)
    {
        //cout << d * d - y * y << " " << floor(sqrt(d * d - y * y)) <<endl;
        answer += floor(sqrt(d2 - y * y)) / k + 1;
        
        y += k;
    }
    
    
    return answer;
}