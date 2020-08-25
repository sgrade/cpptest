// A. Minutes Before the New Year

#include <stdio.h>


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	while(t--){
		
		int h, m;
		scanf("%d %d\n", &h, &m);
		
		h = 23 - h;
		m = 60 - m;
		
		int result = h*60 + m;
		
		printf("%d\n", result);
		
	}
	
	return 0;
}
