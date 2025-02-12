#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0, a = 0, b = 0;
    
    for(int i = triangle.size() - 1; i >= 0; i--)
    {
        for(int j = 0; j < triangle[i].size() - 1; j++)
        {
            a = triangle[i - 1][j] + triangle[i][j];
            b = triangle[i - 1][j] + triangle[i][j + 1];
            
            if(a < b)
            {
                triangle[i - 1][j] = b;
            }
            else
            {
                triangle[i - 1][j] = a;
            }
        }
    }
    
    return triangle[0][0];
}