#include<iostream>
#include<queue>

using namespace std;

int main(){
	int n, num, max_top, min_top;
	priority_queue<int, vector<int>, greater<int>> minimum_heap;	//위쪽 숫자
	priority_queue<int, vector<int>, less<int>> maximum_heap;	//아래쪽 숫자
	scanf("%d", &n);

	scanf("%d", &num);
	maximum_heap.push(num);
	printf("%d\n", num);

	for(int i = 1; i < n; i++){
		scanf("%d", &num);

		if(maximum_heap.size() > minimum_heap.size()){
			minimum_heap.push(num);
		}
		else{
			maximum_heap.push(num);
		}
		if(!minimum_heap.empty() && maximum_heap.top() > minimum_heap.top()){
			max_top = maximum_heap.top();
			min_top = minimum_heap.top();
			maximum_heap.pop();
			minimum_heap.pop();
			maximum_heap.push(min_top);
			minimum_heap.push(max_top);
		}
		
		printf("%d\n", maximum_heap.top());
	}

}