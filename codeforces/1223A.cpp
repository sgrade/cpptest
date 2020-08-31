// A. CME

#include <stdio.h>


int main(){
	
	int q;
	scanf("%d\n", &q);
	
	while(q--){
			
		int n;
		scanf("%d\n", &n);
		
		// left side of "=" should be at least 1+1
		// but, if we start iterating from 1, time limit exceeded
		// so, at least one of the terms should be optimized
		int secondNumber = n/2 - 1;
		
		// summary should be at least 1+1=2
		if (secondNumber == 0) secondNumber = 1;
		
		while(true){
			// total of both sides from "=" should be >= n
			// this is why *2
			if ((1+secondNumber)*2 < n){
				secondNumber++;
			}
			else {
				break;
			}
		}
		printf("%d\n", (1+secondNumber)*2 - n);
		
	}
	
	return 0;
}
