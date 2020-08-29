// A. Frog Jumping

#include <stdio.h>


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	while (t--){
		
		// if int, the results of multiplication is out of int range
		long long a, b, k;
		scanf("%lld %lld %lld\n", &a, &b, &k);
		
		long long position = a*(k/2) - b*(k/2) + a*(k%2);
		printf("%lld\n", position);
		
	}
	
	return 0;
}
