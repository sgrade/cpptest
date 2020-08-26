// A. LCM Problem

#include <stdio.h>


int main(){
	
	int t;
	scanf("%d\n", &t);
	
	while (t--){
		
		int l, r;
		scanf("%d %d\n", &l, &r);
		
		// editorial - https://codeforces.com/blog/entry/80809
		
		if (l*2 > r) printf("%d %d\n", -1, -1);
		else printf("%d %d\n", l, 2*l);
		
	}
	
	return 0;
}
