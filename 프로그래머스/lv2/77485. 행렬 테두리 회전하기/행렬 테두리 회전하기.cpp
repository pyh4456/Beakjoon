#include <string>
#include <vector>
#include <iostream>
#include "limits.h"
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int **matrix;
    int count = 0;
    
    matrix = new int*[rows];
    for(int i = 0; i < rows; i++){
        matrix[i] = new int[columns];
        for(int j = 0; j < columns; j++){
            count++;
            matrix[i][j] = count;
        }
    }
    
    int temp = 0, next;
    int least = INT_MAX;
    for(auto query : queries){
        least = INT_MAX;
        temp = matrix[query[0] - 1][query[1] - 1];
        for(int i = query[1] - 1; i < query[3] - 1; i++){
            if(temp < least)
                least = temp;
            next = matrix[query[0] - 1][i + 1];
            matrix[query[0] - 1][i + 1] = temp;
            temp = next;
        }
        for(int i = query[0] - 1; i < query[2] - 1; i++){
            if(temp < least)
                least = temp;
            next = matrix[i + 1][query[3] - 1];
            matrix[i + 1][query[3] - 1] = temp;
            temp = next;
        }
        for(int i = query[3] - 1; i > query[1] - 1; i--){
            if(temp < least)
                least = temp;
            next = matrix[query[2] - 1][i - 1];
            matrix[query[2] - 1][i - 1] = temp;
            temp = next;
        }
        for(int i = query[2] - 1; i > query[0] - 1; i--){
            if(temp < least)
                least = temp;
            next = matrix[i - 1][query[1] - 1];
            matrix[i - 1][query[1] - 1] = temp;
            temp = next;
        }
        answer.push_back(least);
    }
    
    return answer;
}