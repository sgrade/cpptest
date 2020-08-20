// B. Even Array
// Solved after reading the editorial
// https://codeforces.com/blog/entry/78864

#include <iostream>
#include <numeric>		// accumulate

using namespace std;


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	while(t--){
		
		int n;
		scanf("%d\n", &n);
		
		int odd=0, even=0, tmp;
		for (int i=0; i<n; ++i){
			scanf("%d", &tmp);
			if (i%2 != tmp%2) {
				if (i%2 != 0) ++even;
				else ++odd;
			}
		}
		
		if (odd!=even) printf("%d\n", -1);
		else printf("%d\n", odd);
		
	}
	
	return 0;
}
