#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string.h>
using namespace std;

int cnt = 0;

int recursion(const char* s, int l, int r) {
    cnt++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    cnt = 0;
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    int n;
    string s;
    
    cin >> n;
    
    for(int i = 0; i< n;i++){
        cin >> s;
        cout << isPalindrome(s.c_str()) << " " << cnt << endl;
    }
}