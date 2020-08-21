// A. Park Lighting

#include <stdio.h>
#include <algorithm>

int main(){
	
	int t, n, m;
	scanf("%d\n", &t);
	
	while (t--){
		
		scanf("%d %d\n", &n, &m);
		
		if (n < m) std::swap(n, m);
		
		if (n==1) printf("%d\n", 1);
		else if (n%2 ==0) printf("%d\n", n/2*m);
		else printf("%d\n", n/2*m + (m%2?(m/2+1):(m/2)));
		
	}
		
	return 0;
}
