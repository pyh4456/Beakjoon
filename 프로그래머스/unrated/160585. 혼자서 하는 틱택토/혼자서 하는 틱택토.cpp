#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> board) {
    int cntO = 0, cntX = 0;
    bool O_complete = false, X_complete = false;

    //O, X 개수 세기
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
        if(board[i][j] == 'O')
            cntO++;
            else if(board[i][j] == 'X')
                cntX++;
        }
    }
    
    //완성 여부 체크
    //가로
    if(board[0][0] == board[0][1] && board[0][1] == board[0][2]){
        if(board[0][0] == 'O'){
            O_complete = true;
        }else if(board[0][0] == 'X'){
            X_complete = true;
        }
    }
    if(board[1][0] == board[1][1] && board[1][1] == board[1][2]){
         if(board[1][0] == 'O'){
            O_complete = true;
        }else if(board[1][0] == 'X'){
            X_complete = true;
        }
    }
    if(board[2][0] == board[2][1] && board[2][1] == board[2][2]){
         if(board[2][0] == 'O'){
            O_complete = true;
        }else if(board[2][0] == 'X'){
            X_complete = true;
        }
    }
    //세로
    if(board[0][0] == board[1][0] && board[1][0] == board[2][0]){
         if(board[0][0] == 'O'){
            O_complete = true;
        }else if(board[0][0] == 'X'){
            X_complete = true;
        }
    }
    if(board[0][1] == board[1][1] && board[1][1] == board[2][1]){
         if(board[0][1] == 'O'){
            O_complete = true;
        }else if(board[0][1] == 'X'){
            X_complete = true;
        }
    }
    if(board[0][2] == board[1][2] && board[1][2] == board[2][2]){
         if(board[0][2] == 'O'){
            O_complete = true;
        }else if(board[0][2] == 'X'){
            X_complete = true;
        }
    }
    //대각선
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
         if(board[0][0] == 'O'){
            O_complete = true;
        }else if(board[0][0] == 'X'){
            X_complete = true;
        }
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        if(board[0][2] == 'O'){
            O_complete = true;
        }else if(board[0][2] == 'X'){
            X_complete = true;
        }
    }
    
    
    if(X_complete && O_complete) return 0;
    cout <<"1";
    if( X_complete && cntX - cntO != 0 )
        return 0;
      cout <<"1";
    if( O_complete && cntO - cntX != 1 )
        return 0;
      cout <<"1";
    if( !(cntO - cntX == 1 || cntO - cntX == 0) )
        return 0;
  cout <<"1";
    return 1;
}