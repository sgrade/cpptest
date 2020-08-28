// B. Anton and Digits

#include <stdio.h>
#include <algorithm>


int main(){
	
	int k2, k3, k5, k6;
	scanf("%d %d %d %d\n", &k2, &k3, &k5, &k6);
	
	int numOf256 = std::min( {k2, k5, k6} );
	
	k2 -= numOf256;
	//k5 -= numOf256;
	//k6 -= numOf256;
	
	int numOf32 = std::min ( {k2, k3} );

	printf("%d\n", numOf256*256 + numOf32*32);
	
	return 0;
}
