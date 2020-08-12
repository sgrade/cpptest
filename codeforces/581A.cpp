//A. Vasya the Hipster

#include <stdio.h>

using namespace std;

int main(){
	
	int a, b;
	scanf("%d %d", &a, &b);
	
	int daysDifferent=0, daysSame=0;
	
	if (a<b) {
		daysDifferent=a;
		daysSame=(b-a)/2;
	}
	else if (a>b) {
		daysDifferent=b;
		daysSame=(a-b)/2;
	}
	else {
		daysDifferent = a;
		daysSame =0;
	}
	
	printf("%d %d", daysDifferent, daysSame);
	
	return 0;
}
