// A. Most Unstable Array
// Editorial - https://codeforces.com/blog/entry/77373

#include <iostream>
#include <numeric>

using namespace std;


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	while (t--){
		
		int n, m;
		scanf("%d %d\n", &n, &m);
		
		// Editorial: 
		// three below lines can be replaced with min(2,n−1)⋅m
		if (n==1) printf("%d\n", 0);
		else if (n==2) printf("%d\n", m);
		else printf("%d\n", 2*m);
			
	}
	
	return 0;
}
