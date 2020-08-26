// A. Sereja and Dima

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
	
	int n;
	scanf("%d\n", &n);
	
	int tmp;
	vector<int> v;
	for (int i=0; i<n; ++i){
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	
	auto it = v.begin();
	auto rit = v.rbegin();
	
	int results[2]={0}, flag=0;
	for (int i=0; i<n; ++i){
		
		//printf("i: %d\n", i);
		//printf("%d %d\n", *it, *rit);
		
		if (*it > *rit) {
			results[flag] += *it;
			it++;
		}
		else {
			results[flag] += *rit;
			rit++;
		}
		
		//printf("%d %d\n", results[0], results[1]);
		
		flag = !flag;
		//printf("%d\n", flag);
		
	}
	
	printf("%d %d\n", results[0], results[1]);
	
	return 0;
}
