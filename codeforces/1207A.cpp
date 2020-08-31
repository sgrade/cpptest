// A. There Are Two Types Of Burgers

#include <stdio.h>


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	while(t--){
		
		int b, p, f;
		scanf("%d %d %d\n", &b, &p, &f);
		
		int h, c;
		scanf("%d %d\n", &h, &c);
		
		if (b==1){
			printf("0\n");
			continue;
		}
		
		int profit = 0;
		
		while (p>0 && f>0 && b/2>0){
			if ( h > c ) {
				profit += h;
				p--;
			}
			else {
				profit += c;
				f--;
			}
			b -= 2;
		}
		
		while (p>0 && b/2>0){
			profit +=h;
			p--;
			b-=2;
		}
		while (f>0 && b/2>0){
			profit += c;
			f--;
			b-=2;
		}
		
		printf("%d\n", profit);
		
	}
	
	return 0;
}
