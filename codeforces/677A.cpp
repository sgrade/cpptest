// A. Vanya and Fence

#include <iostream>

int main(){
	
	int n, h;
	scanf("%d %d", &n, &h);
	
	int w=0, personHeight;
	
	for (int i=0; i<n; ++i){
		
		scanf("%d", &personHeight);
		
		if (personHeight > h){
			w+=2;
		}
		else w++; 
	}
	
	printf("%d", w);
	
	return 0;
}
