#include <string>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int TimeToInt(string time)
{
    int output;
    
    output = stoi(time.substr(0, 2)) * 60;
    output += stoi(time.substr(3, 2));
    
    return output;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";  

    int len_int, pos_int, op_start_int, op_end_int;
    
    len_int = TimeToInt(video_len);
    pos_int = TimeToInt(pos);
    op_start_int = TimeToInt(op_start);
    op_end_int = TimeToInt(op_end);
    
    for(auto cmd : commands)
    {    
        if(pos_int >= op_start_int && pos_int < op_end_int)
        {
            pos_int = op_end_int;
        }
        
        if(cmd == "next")
        {
            if(len_int - pos_int <= 10)
            {
                pos_int = len_int;
            }
            else
            {
                pos_int += 10;
            }
        }
        else if(cmd == "prev")
        {
            if(pos_int <= 10)
            {
                pos_int = 0;
            }
            else
            {
                pos_int -= 10;
            }
        }
    }
        
    if(pos_int >= op_start_int && pos_int < op_end_int)
    {
        pos_int = op_end_int;
    }
    
    string minute, second;
    minute = to_string(pos_int / 60);
    second = to_string(pos_int % 60);
    
    if(minute.length() == 1)
    {
        minute = "0" + minute;
    }
    
    if(second.length() == 1)
    {
        second = "0" + second;
    }
    
    answer += minute + ":" + second;
    
    return answer;
}