// A. Domino piling

#include <iostream>

int main(){
	
	int m, n;
	scanf("%d %d", &m, &n);
	
	// base case
	if (m < 2 && n <2){
		printf("%d", 0);
		exit(0);
	}
	
	if (m%2 == 0){
		printf("%d", (m/2)*n);
		exit(0);
	}
	else if (n%2 == 0){
		printf("%d", (n/2)*m);
		exit(0);
	}
	
	else {
		if (m > 1) {
			printf("%d", ((m-1)/2*n + n/2));
		}
		else {
			printf("%d", ((n-1)/2*m + m/2));
		}
	}
	
return 0;
}
