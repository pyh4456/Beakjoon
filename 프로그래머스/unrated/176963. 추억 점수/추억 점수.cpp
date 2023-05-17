#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> map;
    int cnt = 0;
    
    for(int i = 0; i < name.size(); i++){
        map[name[i]] = yearning[i];
    }
    
    for(int i = 0; i < photo.size(); i++){
        cnt = 0;
        for(int j = 0; j < photo[i].size(); j++){
            cnt += map[photo[i][j]];
        }
        answer.push_back(cnt);
    }
    
    
    return answer;
}