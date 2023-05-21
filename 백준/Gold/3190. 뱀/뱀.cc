#include <iostream>
#include <deque>
using namespace std;

enum direction {
	UP, RIGHT, DOWN, LEFT
};

struct Move {
	int time;
	char direct;
};

struct Snake {
	direction direct;
	int row, column;
};

int** board; // 0: empty, 1: apple, 2: snake
int move_index = 0, n;
Move* moving;
deque<Snake> deq;

bool move_snake(direction direct) {
	Snake s;
	int row, column;
	row = deq.front().row;
	column = deq.front().column;
	switch (direct) {
	case UP:
		if (row == 0) {	//end of board
			return false;
		}
		else {
			if (board[row - 1][column] == 2)	//collide with the body
				return false;

			if (board[row - 1][column] == 0) {	//no apple
				board[deq.back().row][deq.back().column] = 0;
				deq.pop_back();
			}
			board[row - 1][column] = 2;
			s.row = row - 1;
			s.column = column;
			deq.push_front(s);
			board[row][column] = 2;

			return true;
		}
		break;
	case RIGHT:
		if (column == n - 1) {	//end of board
			return false;
		}
		else {
			if (board[row][column + 1] == 2)	//collide with the body
				return false;

			if (board[row][column + 1] == 0) {	//no apple
				board[deq.back().row][deq.back().column] = 0;
				deq.pop_back();
			}
			board[row][column + 1] = 2;
			s.row = row;
			s.column = column + 1;
			deq.push_front(s);
			
			return true;
		}
		break;
	case DOWN:
		if (row == n - 1) {	//end of board
			return false;
		}
		else {
			if (board[row + 1][column] == 2)	//collide with the body
				return false;

			if (board[row + 1][column] == 0) {	//no apple
				board[deq.back().row][deq.back().column] = 0;
				deq.pop_back();
			}
			board[row + 1][column] = 2;
			s.row = row + 1;
			s.column = column;
			deq.push_front(s);

			return true;
		}
		break;
	case LEFT:
		if (column == 0) {	//end of board
			return false;
		}
		else {
			if (board[row][column - 1] == 2)	//collide with the body
				return false;

			if (board[row][column - 1] == 0) {	//no apple
				board[deq.back().row][deq.back().column] = 0;
				deq.pop_back();
			}
			board[row][column - 1] = 2;
			s.row = row;
			s.column = column - 1;
			deq.push_front(s);

			return true;
		}
		break;
	}
}

direction turn(direction current, char direct) {
	direction out = current;

	switch (current) {
	case UP:
		if (direct == 'D') {
			out = RIGHT;
		}
		else {
			out = LEFT;
		}
		break;
	case RIGHT:
		if (direct == 'D') {
			out = DOWN;
		}
		else {
			out = UP;
		}
		break;
	case DOWN:
		if (direct == 'D') {
			out = LEFT;
		}
		else {
			out =RIGHT;
		}
		break;
	case LEFT:
		if (direct == 'D') {
			out = UP;
		}
		else {
			out = DOWN;
		}
		break;
	}

	return out;
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}cout << endl;
}

int main() {
	int k, r, c, l, x, time = 0, move_cnt = 0, d;
	char temp;
	Snake s;
	direction move_direction = RIGHT;

	s.direct = RIGHT;
	s.row = 0; s.column = 0;

	cin >> n;

	board = new int* [n];
	for (int i = 0; i < n; i++) {
		board[i] = new int[n];
		for (int j = 0; j < n; j++) {
			board[i][j] = 0;
		}
	}

	deq.push_front(s);
	board[0][0] = 2;

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> r >> c;
		board[r - 1][c - 1] = 1;
	}
	
	cin >> l;
	moving = new Move[l];
	for (int i = 0; i < l; i++) {
		cin >> x >> temp;

		moving[i].time = x;
		moving[i].direct = temp;
	}

	while (1) {
		if (move_cnt < l) {
			if (time == moving[move_cnt].time) {
				move_direction = turn(move_direction, moving[move_cnt].direct);
				move_cnt++;
			}
		}
		
		if (!move_snake(move_direction))
			break;
		time++;
	}
	cout << time + 1 << endl;

}