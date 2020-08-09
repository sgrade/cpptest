// B. Drinks

#include <iostream>

int main(){
	
	int n, p;
	scanf("%d", &n);
	
	float output = 0;
	
	for (int i=0; i<n; ++i){
		scanf("%d", &p);
		output+=p;
	}
	
	output /= n;
	
	printf("%f", output);
	
	return 0;
}
