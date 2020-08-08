// A. Magnets

#include <iostream>

int main(){
	
	int n;
	scanf("%d", &n);
	
	int groups=0;
	
	if (n==1) {
		printf("%d", 1);
		exit(0);
	}
	
	int first, second;
	int prevSecond=0;
	
	for (int i=0; i<n; ++i){
		
		// Input is not space-separated, so we need to parse it
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 10){
			first = 1;
			second = 0;
		}
		else {
			first = 0;
			second = 1;
		}
		// printf("First: %d, Second: %d\n", first, second);
		
		//first magnet
		if (i==0){
			groups++;
			first=prevSecond;
		}
		
		
		else if (first==prevSecond){
			groups++;
		}
		prevSecond=second;
		// printf("Current number of groups: %d\n", groups);
	}
	
	printf("%d", groups);
	
	return 0;
}
