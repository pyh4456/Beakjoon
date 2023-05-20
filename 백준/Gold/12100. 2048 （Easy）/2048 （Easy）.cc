#include <iostream>

using namespace std;

int find_biggest(int** board, int size) {
    int out = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (out < board[i][j])
                out = board[i][j];
        }
    }

    return out;
}

void move_board(int** board, int size, int direction) {
    //direction : 0 = right, 1 = down, 2 = left, 3 = up
    int prev_index, temp;

    switch (direction) {
    case 0: //right
        for (int i = 0; i < size; i++) {
            prev_index = size - 1;
            for (int j = size - 2; j >= 0; j--) {
                if (board[i][j] > 0) {
                    if (board[i][prev_index] == 0) {
                        board[i][prev_index] += board[i][j];
                        board[i][j] = 0;
                    }
                    else if (board[i][j] == board[i][prev_index]) {
                        board[i][prev_index] += board[i][j];
                        prev_index = prev_index - 1;
                        board[i][j] = 0;
                    }
                    else {
                        temp = board[i][j];
                        board[i][j] = 0;
                        board[i][prev_index - 1] = temp;
                        prev_index = prev_index - 1;
                    }

                }
            }
        }
        break;
    case 1: //down
        for (int j = 0; j < size; j++) {
            prev_index = size - 1;
            for (int i = size - 2; i >= 0; i--) {

                if (board[i][j] > 0) {
                    if (board[prev_index][j] == 0) {
                        board[prev_index][j] += board[i][j];
                        board[i][j] = 0;
                    }
                    else if (board[i][j] == board[prev_index][j]) {
                        board[prev_index][j] += board[i][j];
                        prev_index = prev_index - 1;
                        board[i][j] = 0;
                    }
                    else {
                        temp = board[i][j];
                        board[i][j] = 0;
                        board[prev_index - 1][j] = temp;
                        prev_index = prev_index - 1;
                    }

                }
            }
        }
        break;
    case 2: //left
        for (int i = 0; i < size; i++) {
            prev_index = 0;
            for (int j = 1; j < size; j++) {
                if (board[i][j] > 0) {
                    if (board[i][prev_index] == 0) {
                        board[i][prev_index] += board[i][j];
                        board[i][j] = 0;
                    }
                    else if (board[i][j] == board[i][prev_index]) {
                        board[i][prev_index] += board[i][j];
                        prev_index = prev_index + 1;
                        board[i][j] = 0;
                    }
                    else {
                        temp = board[i][j];
                        board[i][j] = 0;
                        board[i][prev_index + 1] = temp;
                        prev_index = prev_index + 1;
                    }
                }
            }
        }
        break;
    case 3: //up
        for (int j = 0; j < size; j++) {
            prev_index = 0;
            for (int i = 1; i < size; i++) {
                if (board[i][j] > 0) {
                    if (board[prev_index][j] == 0) {
                        board[prev_index][j] += board[i][j];
                        board[i][j] = 0;
                    }
                    else if (board[i][j] == board[prev_index][j]) {
                        board[prev_index][j] += board[i][j];
                        prev_index = prev_index + 1;
                        board[i][j] = 0;
                    }
                    else {
                        temp = board[i][j];
                        board[i][j] = 0;
                        board[prev_index + 1][j] = temp;
                        prev_index = prev_index + 1;
                    }
                }
            }
        }
    }
}

void copy_board(int**& board, int**& copy, int size) {

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            copy[i][j] = board[i][j];
        }
    }
}
void print_board(int** board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int dfs(int**& board, int move, int size) {
    int** copy = new int* [size];
    int out = 0, temp;
    if (move == 0) {
        return find_biggest(board, size);
    }

    for (int i = 0; i < size; i++) {
        copy[i] = new int[size];
    }
    for (int i = 0; i < 4; i++) {
        copy_board(board, copy, size);
        move_board(copy, size, i);

        temp = dfs(copy, move - 1, size);
        if (out < temp) {
            out = temp;
        }
    }

    return out;
}


int main() {
    int n, ** board;

    cin >> n;

    board = new int* [n];
    for (int i = 0; i < n; i++) {
        board[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int** copy = new int* [n];

    for (int i = 0; i < n; i++) {
        copy[i] = new int[n];
    }

    cout << dfs(board, 5, n);

}