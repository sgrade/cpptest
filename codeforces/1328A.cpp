// A. Divisibility Problem

#include <iostream>

int main(){
	
	int t, a, b;
	scanf("%d", &t);
	
	int output, remainder=0;
	while(t){
		
		output=0;
		
		scanf("%d %d", &a, &b);
		if(a<b){
			output+= b-a;
			a=b;
		}
		else if(a>b){
			remainder = a%b;
			if(remainder != 0) output += b-remainder;
			else output=0;
		}
		else output=0;
		printf("%d\n", output);
		
		--t;
	}
	
	return 0;
}
