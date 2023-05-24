#include<iostream>

using namespace std;

struct Stuff{
	int w;
	int v;
};

int knapsack(int **benefit, Stuff *stuffs, int n, int k){
	int cnt_w = 0, temp;

	for(int i = 0; i < n; i++){
		benefit[i][0] = 0;
	}
	for(int i = 0; i < k; i++){
		benefit[0][i] = 0;
	}

	for(int i = 1; i <= n; i++){
		for(int w = 1; w <= k; w++){
			if(w >= stuffs[i - 1].w){
				temp = benefit[i - 1][w - stuffs[i - 1].w] + stuffs[i - 1].v;
				if(temp > benefit[i - 1][w]){
					benefit[i][w] = temp;
				}else{
					benefit[i][w] = benefit[i - 1][w];
				}
			}else{
				benefit[i][w] = benefit[i - 1][w];
			}
		}
	}

	return benefit[n][k];
}

int main(){
	int n,  k, cnt = 0, greatest = 0;
	int **benefit;
	Stuff *stuffs;

	cin >> n >> k;

	benefit = new int*[n + 1];
	for(int i = 0; i <= n; i++){
		benefit[i] = new int[k + 1];
	}
	stuffs = new Stuff[n];

	for(int i = 0; i < n; i++){
		cin >> stuffs[i].w >> stuffs[i].v;
	}
	
	cout << knapsack(benefit, stuffs, n, k);
}