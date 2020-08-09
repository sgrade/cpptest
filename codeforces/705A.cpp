// A. Hulk

#include <iostream>

int main(){
	
	int n;
	scanf("%d", &n);
	
	if (n==1){
		printf("I hate it");
		exit(0);
	}
	
	else{
		printf("I hate ");
		for (int i=0; i<n-1; ++i){
			printf("that I love ");
			if (i==n-2){
				break;
			}
			else {
				printf("that I hate ");
				++i;
			}
		}
		printf("it");
	}
	
	return 0;
}
