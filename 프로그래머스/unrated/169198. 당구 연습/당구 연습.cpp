#include <string>
#include <vector>
#include <limits.h>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    int least = INT_MAX;
    int temp;
    
    for(int i = 0; i < balls.size(); i++){
        least = INT_MAX;
        
        if( !(startY == balls[i][1] && startX > balls[i][0])){
            temp = pow(startX + balls[i][0], 2) + pow(startY - balls[i][1], 2);//왼쪽으로 반전
            if(temp < least) least = temp;
        }
         if( !(startY == balls[i][1] && startX < balls[i][0])){
            temp = pow((m - startX) + (m - balls[i][0]), 2) + pow(startY - balls[i][1], 2);//오른쪽으로 반전
            if(temp < least) least = temp;
         }
        if( !(startX == balls[i][0] && startY < balls[i][1])){
            temp = pow(startX - balls[i][0], 2) + pow((n - startY) + (n - balls[i][1]), 2);//위쪽으로 반전
            if(temp < least) least = temp;
        }
        if( !(startX == balls[i][0] && startY > balls[i][1])){
            temp = pow(startX - balls[i][0], 2) + pow(startY + balls[i][1], 2);//아래쪽으로 반전
            if(temp < least) least = temp;
        }
        
        
    
        answer.push_back(least);
    }
    
    
    return answer;
}