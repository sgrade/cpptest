// A. Puzzle Pieces

#include <stdio.h>


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	while (t--){
		
		int n, m;
		scanf("%d %d\n", &n, &m);
		
		// editorial
		if ( (n>2 && m>1) || (n>1 && m>2) ) printf("NO\n");
		else printf ("YES\n");
		
	}
	
	return 0;
}
