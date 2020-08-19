// A. Required Remainder

#include <iostream>

using namespace std;


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	while(t--){
		
		int x, y, n;
		scanf("%d %d %d\n", &x, &y, &n);
		
		// TARGET: max k, when k%x = y,	k<n;
		
		// cout << "n%x = " << n%x << endl;
		
		int output = 0;
		
		if (n%x == y){
			printf("%d\n", n);
			continue;
		}
		
		else if (n%x < y) {
			output = n + (y-n%x) - x;
			
		}
		
		else if (n%x > y) {
			output = n - (n%x - y);
		}
		
		printf("%d\n", output);
		
	}
	
	return 0;
}
