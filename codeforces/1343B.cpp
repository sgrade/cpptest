// B. Balanced Array

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	int t;
	scanf("%d", &t);
	
	int n;
	
	for (int i=0; i<t; ++i){
		
		scanf("%d", &n);
		//cout << "n: " << n << endl;
		
		if (n==2){
			printf("NO\n");
			//cout << "==================" << endl;
			continue;
		}
		
		vector<int> even;
		vector<int> odd;
		
		int j, sumOfEven=0, sumOfOdd=0;
		for (j=1; j<(n/2); ++j){
			//cout << "j: " << j << endl;
			sumOfEven+=j*2;
			even.push_back(j*2);
			sumOfOdd+=j*2-1;
			odd.push_back(j*2-1);
		}
		if (j==n/2){
			even.push_back(j*2);
			sumOfEven+=j*2;
			int lastOdd = sumOfEven-sumOfOdd;
			if (lastOdd%2 == 0) {
				printf("NO\n");
				//cout << "==================" << endl;
				continue;
			}
			odd.push_back(lastOdd);
		}
		
		printf("YES\n");
		for (auto& it: even){
			printf("%d ", it);
		}
		for (auto& it: odd){
			printf("%d ", it);
		}
		
		cout << endl;
		//cout << "==================" << endl;
	}
	
	
	
	return 0;
}
