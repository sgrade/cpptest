// A. Elephant

#include <iostream>

int main(){
	
	int x, steps=0;
	scanf("%d", &x);
	// printf("%d", x);
		
	while (x>=5) {
		x-=5;
		steps+=1;
		//printf("Minus 5 %d\n", x);
	}
	while (x>=4){
		x-=4;
		steps+=1;
		//printf("Minus 4 %d\n", x);
	}
	while (x>=3){
		x-=3;
		steps+=1;
		//printf("Minus 3 %d\n", x);
	}
	while (x>=2){
		x-=2;
		steps+=1;
		//printf("Minus 2 %d\n", x);
	}
	if (x>0) {
		x -=1;
		steps+=1;
		//printf("Minus 1 %d\n", x);
	}
	printf("%d", steps);
	
	return 0;
}
