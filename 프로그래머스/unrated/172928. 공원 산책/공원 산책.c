#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
// park_len은 배열 park의 길이입니다.
// routes_len은 배열 routes의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* park[], size_t park_len, const char* routes[], size_t routes_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * 2);
    int size = strlen(park[0]);
    int current_y, current_x;
    int flag = 0;

    for(int i = 0; i < park_len; i++){
         for(int j = 0; j < size; j++){
             if(park[i][j] == 'S'){
                 answer[0] = i;
                 answer[1] = j;
             }
         }
    }
    int n;
    for(int i = 0; i < routes_len; i++){
        flag = 1;
        n = routes[i][2] - 48;
        
        switch(routes[i][0]){
            case 'N':
                if(answer[0] - n >= 0){                
                     for(int i = 1; i <= n; i++){
                         if(park[answer[0] - i][answer[1]] == 'X'){
                             flag = 0;
                             break;
                         }
                     }
                    if(flag == 1){
                        answer[0] -= n;
                    }
                }
                break;
            case 'S':
                if(answer[0] + n < park_len){       
                    for(int i = 1; i <= n; i++){
                        printf("%c\n", park[answer[0] + i][answer[1]]);
                        if(park[answer[0] + i][answer[1]] == 'X'){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag == 1){
                       answer[0] += n;
                    }
                }
                break;
            case 'W':
                if(answer[1] - n >= 0){
                    for(int i = 1; i <= n; i++){
                        if(park[answer[0]][answer[1] - i] == 'X'){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag == 1){
                       answer[1] -= n;
                    }
                }
                break;
            case 'E':
                if(answer[1] + n < size){    
                    for(int i = 1; i <= n; i++){
                        if(park[answer[0]][answer[1] + i] == 'X'){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag == 1){
                       answer[1] += n;
                    }
                }
                break;
        }
        printf("%d,%d\n",answer[0], answer[1]);
    }
    
    return answer;
}