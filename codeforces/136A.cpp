// A. Presents

#include <iostream>
#include <stdlib.h>

int main(){
	
	int n, destIndex;
	scanf("%d", &n);
	
	int output[n];
	
	for (int i=0; i<n; ++i){
		scanf("%d", &destIndex);		
		output[destIndex-1] = i+1;
	}
	
	
	for (int j=0; j<n; ++j){
		if (j<n+1) printf("%d ", output[j]);
		else printf("%d", output[j]);
	}
	
	return 0;
}
