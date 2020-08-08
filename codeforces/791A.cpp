// A. Bear and Big Brother

#include <iostream>

int main(){
	
	int a, b, years=0;
	scanf("%d %d", &a, &b);
	
	while(true){
		a=a*3;
		b=b*2;
		years++;
		if (a > b) {
			printf("%d", years);
			exit(0);
		}
	}
	
	return 0;
}
