#include<iostream>
#include<map>
#include<list>
using namespace std;

class Building {
public:
	int number = 0;
	map<int, int> necessary_condition;	//이 건물을 짓기위한 조건(필요조건)
	list<int> sufficient_condition;		//이 건물이 필요조건인 건물들(충분조건)
	int condition_size = 0;
	int time = 0;
	bool buildable =true;
	bool complete = false;

	inline void building_set(int num, int t) {	//건물 번호, 건설 시간 설정
		this->number = num;
		this->time = t;
		buildable = true;
		condition_size = 0;
	}
	inline void necessary_condition_set(int cond) {	//건물번호 n을 필요조건으로 설정
		necessary_condition[cond] = 1;
		condition_size++;
		buildable = false;
	}
	inline void sufficient_condition_set(int cond) {	//건물번호 n을 충분조건으로 설정
		sufficient_condition.push_back(cond);
	}
	inline int is_buildable() {
		return buildable;
	}
	inline int is_complete() {
		return complete;
	}
	inline void condition_satisfact(int n) {	//건물번호 n의 조건 충족
		if (necessary_condition[n] == 1) {
			necessary_condition[n] = 0;
			condition_size--;

			if (condition_size == 0)
				buildable = true;
		}
	}
	inline bool construct(int t) {	//t의 시간동안 건설, 건설이 완료되면 true 리턴
		time -= t;
		if (time <= 0) {
			complete = true;
			return true;	//complete construction
		}
		
		return false;	//imcomplete construction
	}
};

inline void condition_func(Building*& building, int num) {
	list<int>::iterator iter;

	for (iter = building[num].sufficient_condition.begin(); iter != building[num].sufficient_condition.end(); iter++) {
		building[*iter].condition_satisfact(num);
	}
}

/*
void print(list<int> buildable, list<int> not_buildable) {
	list<int>::iterator iter;
	cout << "builable" << endl;
	for (iter = buildable.begin(); iter != buildable.end(); iter++) {
	
		cout << *iter << " ";
	}cout << endl;
	cout << "not buildable" << endl;
	for (iter = not_buildable.begin(); iter != not_buildable.end(); iter++) {
	
		cout << *iter << " ";
	}cout << endl;
}*/

int main() {
	int test, n, k, d, x, y, w, temp;
	int cnt = 0, least = 100000;
	Building* building;
	list<int> buildable;
	list<int> not_buildable;
	list<int>::iterator iter, to_erase;

	cin >> test;

	for (int i = 0; i < test; i++) { //test case
		cnt = 0;
		cin >> n >> k;
		building = new Building[n];

		for (int j = 0; j < n; j++) {
			cin >> d;
			building[j].building_set(j, d);
		}
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			building[y - 1].necessary_condition_set(x - 1);
			building[x - 1].sufficient_condition_set(y - 1);
		}
		cin >> w;

		w--;
	
		for (int j = 0; j < n; j++) {
			if (building[j].is_buildable()) {
				buildable.push_back(j);
			}
			else {
				not_buildable.push_back(j);
			}
		}

		while (!building[w].is_buildable()) {
			least = 100000;

			//print(buildable, not_buildable);/////////

			for (iter = buildable.begin(); iter != buildable.end(); iter++) {
				temp = building[*iter].time;
				if (least > temp) {
					least = temp;
				}
			}

			for (iter = buildable.begin(); iter != buildable.end();) {
				if (building[*iter].construct(least)) { //건설 완료
					condition_func(building, *iter);
					iter = buildable.erase(iter);
				}
				else {
					iter++;
				}
			}
			for (iter = not_buildable.begin(); iter != not_buildable.end();) {
				if (building[*iter].is_buildable()) { 
					buildable.push_back(*iter);
					iter = not_buildable.erase(iter);
				}
				else {
					iter++;
				}
			}

			cnt += least;
		}
		buildable.clear();
		not_buildable.clear();
		cout << cnt + building[w].time << endl;
	}

}