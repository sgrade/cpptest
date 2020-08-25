// A. Array with Odd Sum

#include <stdio.h>


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	while (t--){
		
		int n;
		scanf("%d\n", &n);
		
		int tmp, numOfOdds=0;
		for(int i=0; i<n; ++i){
			
			scanf("%d", &tmp);
			if (tmp%2 != 0) numOfOdds += 1;
			//printf("%d ", tmp);
			
		}
		
		if (numOfOdds==0) printf("NO\n");
		else if (numOfOdds==n && n%2==0) printf("NO\n");
		else printf("YES\n");
		
	}
	
	return 0;
}
