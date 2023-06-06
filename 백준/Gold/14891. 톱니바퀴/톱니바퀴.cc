#include <iostream>

using namespace std;

enum POLE {
	N, S
};

class Gear {
public:
	POLE twelve;	//12시 방향의 자성
	POLE three;		//3시 방향의 자성
	POLE nine;		//9시 방향의 자성
	POLE state[8];
	int index_twelve;	//12시 방향의 index;
	int index_three;	//3시 방향의 indxe;
	int index_nine;		//9시 방향의 index
	Gear(POLE s[8]) {
		for (int i = 0; i < 8; i++) {
			state[i] = s[i];
		}
		twelve = state[0];
		three = state[2];
		nine = state[6];
		index_twelve = 0;
		index_three = 2;
		index_nine = 6;
	}
	void counterclockwise() {
		index_twelve++;
		index_three++;
		index_nine++;

		if (index_twelve == 8)
			index_twelve = 0;
		if (index_three == 8)
			index_three = 0;
		if (index_nine == 8)
			index_nine = 0;

		twelve = state[index_twelve];
		three = state[index_three];
		nine = state[index_nine];
	}
	void clockwise() {
		index_twelve--;
		index_three--;
		index_nine--;

		if (index_twelve == -1)
			index_twelve = 7;
		if (index_three == -1)
			index_three = 7;
		if (index_nine == -1)
			index_nine = 7;

		twelve = state[index_twelve];
		three = state[index_three];
		nine = state[index_nine];
	}

	void print() {
		int cnt = 0;
		int ind = index_twelve;

		while (1) {
			cout << state[ind];
			ind++;
			if (ind == 8)
				ind = 0;
			cnt++;
			if (cnt == 8)
				break;
		}
		cout << endl;
	}
};

int main() {
	string s;
	Gear *one, *two, *three, *four;
	POLE pole[4][8];
	POLE on, tw, th, fo;
	int temp, wise, number, score = 0;

	for (int i = 0; i < 4; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++) {
			if (s[j] == '0') {
				pole[i][j] = N;
			}
			else {
				pole[i][j] = S;
			}
		}
	}

	one = new Gear(pole[0]);
	two = new Gear(pole[1]);
	three = new Gear(pole[2]);
	four = new Gear(pole[3]);

	cin >> temp;

	for (int i = 0; i < temp; i++) {
		cin >> number >> wise;
		
		switch (number) {
		case 1:	//1번을 회전
			if (wise == 1) {	//시계방향
				tw = one->three;
				th = two->three;
				fo = three->three;

				one->clockwise();
				if (tw != two->nine)
					two->counterclockwise();
				else
					break;
				if (th != three->nine)
					three->clockwise();
				else
					break;
				if (fo != four->nine)
					four->counterclockwise();
				else
					break;
			}
			else {	//반시계 방향
				tw = one->three;
				th = two->three;
				fo = three->three;

				one->counterclockwise();
				if (tw != two->nine)
					two->clockwise();
				else
					break;
				if (th != three->nine)
					three->counterclockwise();
				else
					break;
				if (fo != four->nine)
					four->clockwise();
				else
					break;
			}
			break;
		case 2:
			if (wise == 1) {
				on = two->nine;
				th = two->three;
				fo = three->three;

				two->clockwise();
				if (on != one->three)
					one->counterclockwise();

				if (th != three->nine)
					three->counterclockwise();
				else
					break;
				if (fo != four->nine)
					four->clockwise();
				else
					break;
			}
			else {
				on = two->nine;
				th = two->three;
				fo = three->three;

				two->counterclockwise();
				if (on != one->three)
					one->clockwise();

				if (th != three->nine)
					three->clockwise();
				else
					break;
				if (fo != four->nine)
					four->counterclockwise();
				else
					break;
			}
			break;
		case 3:
			if (wise == 1) {
				on = two->nine;
				tw = three->nine;
				fo = three->three;

				three->clockwise();
				if (fo != four->nine)
					four->counterclockwise();

				if (tw != two->three)
					two->counterclockwise();
				else
					break;
				if (on != one->three)
					one->clockwise();
				else
					break;
			}
			  else {
				on = two->nine;
				tw = three->nine;
				fo = three->three;

				three->counterclockwise();
				if (fo != four->nine)
					four->clockwise();

				if (tw != two->three)
					two->clockwise();
				else
					break;
				if (on != one->three)
					one->counterclockwise();
				else
					break;
			}
			  break;
		case 4:
			if (wise == 1) {	//시계방향
				on = two->nine;
				tw = three->nine;
				th = four->nine;

				four->clockwise();
				if (th != three->three)
					three->counterclockwise();
				else
					break;
				if (tw != two->three)
					two->clockwise();
				else
					break;
				if (on != one->three)
					one->counterclockwise();
				else
					break;
			}
			else {	//반시계 방향
				on = two->nine;
				tw = three->nine;
				th = four->nine;

				four->counterclockwise();
				if (th != three->three)
					three->clockwise();
				else
					break;
				if (tw != two->three)
					two->counterclockwise();
				else
					break;
				if (on != one->three)
					one->clockwise();
				else
					break;
			}
			break;
		}
	}

	if (one->twelve == S)
		score += 1;
	if (two->twelve == S)
		score += 2;
	if (three->twelve == S)
		score += 4;
	if (four->twelve == S)
		score += 8;

	cout << score;
}
