#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    int group1_cnt = 0, group2_cnt = 0, index = 0;
    int group2_greatest = 0;
    map<int, bool> map1, map2;
    
    for(int i = 0; i < cards.size(); i++)
    {
        cards[i]--;
    }
    
    for(int i = 0; i < cards.size(); i++)
    {
        index = i;
        map1.clear();
        group1_cnt = 0;
        group2_cnt = 0; group2_greatest = 0;
        
        while(map1[index] == false)
        {
            group1_cnt++;
            map1[index] = true;
            //cout << index << " group1" << endl;
            index = cards[index];
        }
        //cout << "group1_cnt " << group1_cnt << endl;
        
        for(int j = 0; j < cards.size(); j++)
        {
            group2_cnt = 0;
            index = j;
            map2 = map1;
            
            while(map2[index] == false)
            {
                group2_cnt++;
                map2[index] = true;
                //cout << index << " group2" << endl;
                index = cards[index];
            }
            if(group2_cnt > group2_greatest)
            {
                group2_greatest = group2_cnt;
                //cout << "group2_greatest "<< group2_greatest << endl;
            }
            map2 = map1;
        }
        
        if(answer < group1_cnt * group2_greatest)
            answer = group1_cnt * group2_greatest;
    }
    
    return answer;
}