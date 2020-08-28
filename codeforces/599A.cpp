// A. Patrick and Shopping

#include <stdio.h>
#include <algorithm>


int main(){
	
	int d1, d2, d3;
	scanf("%d %d %d\n", &d1, &d2, &d3);
	
	int distance = std::min( {2*d1+2*d2, 2*d1+2*d3, 2*d2+2*d3, d1+d2+d3} );
	printf("%d\n", distance);
	
	return 0;
}
