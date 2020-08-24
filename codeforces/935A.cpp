// A. Fafa and his Company

#include <iostream>


int main(){
	
	int n;
	scanf("%d", &n);
	
	int empNoTl = 0, ways=0;
	for (int tl=1; tl<n; ++tl){
		
		empNoTl = (n - tl) % tl;
		if (empNoTl) continue;
		else ways += 1;
		
	}
	
	printf("%d", ways);
	
	return 0;
}
