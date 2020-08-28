// A. Equalize Prices Again

#include <stdio.h>


int main(){
	
	int q;
	scanf("%d\n", &q);
	
	while (q--){
		
		int n;
		scanf("%d\n", &n);
		
		int tmp=0, sum=0;
		for (int i=0; i<n; ++i) {
			scanf("%d", &tmp);
			sum += tmp;
		}
		//printf("sum: %d\n", sum);
		
		int p;
		if (sum%n==0) p = sum/n;
		else p = sum/n + 1;
		
		printf("%d\n", p);
		
	}
	
	return 0;
}
