#include <iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int case_num, student_num;
	float score, above_average = 0, average = 0;
	vector<float> scores;
	cin >> case_num;

	for (int i = 0; i < case_num; i++) {
		average = 0;
		above_average = 0;
		cin >> student_num;

		for (int j = 0; j < student_num; j++) {
			cin >> score;
			average += score;
			scores.push_back(score);
		}
		
		average /= student_num;

		for (int j = 0; j < scores.size(); j++) {
			if (scores[j] > average) above_average += 1;
		}

		above_average = (above_average / student_num) * 100;
		scores.clear();

		printf("%.3f%%\n", above_average);
		
	}
}