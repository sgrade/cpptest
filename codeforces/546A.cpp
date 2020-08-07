// A. Soldier and Bananas

#include <iostream>
#include <math.h>

int main(){
	
	int k, n, w;
	scanf("%d %d %d", &k, &n, &w);
	
	if (w==0){
		printf("%d", 0);
		exit(0);
	}
	
	int total = 0;
	for (int i=1; i<w+1; ++i) total += i*k;
	
	total -= n;
	
	if (signbit(total)) printf("%d", 0);
	else printf("%d", total);
	
	return 0;
}
