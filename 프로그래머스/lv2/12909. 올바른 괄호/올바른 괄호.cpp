#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = false;
    bool complete = false;
    int left = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            left++;
        }
        else {
            if (left == 0) {
                answer = false;
                break;
            }
            else {
                left--;
            }
        }
        if (i == s.length() - 1)
            complete = true;
    }
    if (left == 0 && complete)
        answer = true;

    return answer;
}
