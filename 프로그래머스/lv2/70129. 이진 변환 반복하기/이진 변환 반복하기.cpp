#include <string>
#include <vector>
#include<iostream>

using namespace std;

string remove_zero(string s) {
    int limit = s.length();
    string out = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            out.append("1");
        }
    }
    return out;
}

string tobinary(int n) {
    int temp = n;
    string out = "";

    while (temp != 0)
    {
        if (temp % 2 == 1)
            out.append("1");
        else
            out.append("0");
        temp /= 2;
    }
    return out;
}

int cnt_zero = 0, cnt = 0;

void transform(string s) {
    int inttemp, size;
    string temp = s;

    while (temp != "1") {
        cnt++;
        size = temp.length();
        temp = remove_zero(temp);
        cout << temp << endl;
        cnt_zero += size - temp.length();

        inttemp = temp.length();
        temp = tobinary(inttemp);
    }
}

vector<int> solution(string s) {
    vector<int> answer;

    transform(s);
    answer.push_back(cnt);
    answer.push_back(cnt_zero);

    return answer;
}
