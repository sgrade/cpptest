// B. Gifts Fixing

#include <iostream>
#include <algorithm>


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	while(t--){
		
		int n;
		scanf("%d\n", &n);
		
		int a[n], b[n];
		int tmp;
		for (int i=0; i<n; ++i){
			scanf("%d", &tmp);
			a[i] = tmp;
		}
		
		for (int i=0; i<n; ++i){
			scanf("%d", &tmp);
			b[i] = tmp;
		}
			
		int minA = *std::min_element(a, a+n);
		int minB = *std::min_element(b, b+n);
		
		// with long I get correct answer in g++ 7.5.0 (my current g++)
		// but on codeforces's g++ (7.3.0) it overflows
		// so, changed to unsigned long long
		unsigned long long moves = 0;
		for (int i=0; i<n; ++i){
			moves += std::max (a[i]-minA, b[i]-minB);
		}
		
		printf("%lld\n", moves);
		
	}
	
	return 0;
}
