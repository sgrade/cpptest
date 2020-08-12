// A. New Year and Hurry

#include <iostream>

using namespace std;

int main(){
	
	int n, k;
	scanf("%d %d", &n, &k);
	
	int timeLeft = 240 - k;
	int i;
	for (i=1; i<n+1; ++i){
		timeLeft -= 5*i;
		if (timeLeft < 0) break;
	}
	
	printf("%d", i-1);
	
	return 0;
}
