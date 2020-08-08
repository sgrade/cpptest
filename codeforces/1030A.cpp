// A. In Search of an Easy Problem

#include <iostream>

int main(){
	
	int n, opinion;
	scanf("%d", &n);
	
	for (int i=0; i<n; ++i){
		scanf("%d", &opinion);
		if (opinion){
			printf("HARD");
			exit(0);
		}
	}
	printf("EASY");
	
	return 0;
}
