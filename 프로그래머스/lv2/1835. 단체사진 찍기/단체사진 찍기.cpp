#include <iostream>
#include <string>
#include <vector>
#include <map>

#define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )
using namespace std;

bool check_conditions(string line, vector<string> data) {
    map<char, int> index;
    int interval;

    for (int i = 0; i < 8; i++) {
        index[line[i]] = i;
    }

    for (int i = 0; i < data.size(); i++) {
        interval = index[data[i][0]] - index[data[i][2]];
        if (interval < 0) {
            interval = interval * -1;
        }
        interval--;

        if (data[i][3] == '=') {
            if (interval != data[i][4] - '0') {
                return false;
            }
        }
        else if (data[i][3] == '<') {
            if (interval >= data[i][4] - '0') {
                return false;
            }
        }
        else if (data[i][3] == '>') {
            if (interval <= data[i][4] - '0') {
                return false;
            }
        }

    }
    return true;
}

int permutation(string line, int depth, int n, int r, vector<string>& data) {
    int cnt = 0;
    char temp;

    if (depth == r) {
        if (check_conditions(line, data)) {
            cnt++;
        }

        return cnt;
    }
    for (int i = depth; i < n; i++) {
        SWAP(line[depth], line[i], temp);
        cnt += permutation(line, depth + 1, n, r, data);
        SWAP(line[depth], line[i], temp);
    }
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string line = "ACFJMNRT";

    answer = permutation(line, 0, 8, 8, data);

    return answer;
}