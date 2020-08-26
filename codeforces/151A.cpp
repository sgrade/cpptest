// A. Soft Drinking

#include <stdio.h>
#include <algorithm>

int main(){
	
	int n, k, l, c, d, p, nl, np;
	scanf("%d %d %d %d %d %d %d %d", &n, &k, &l, &c, &d, &p, &nl, &np);
	
	int mlAvail = k*l;
	int slicesAvail = c*d;
	
	int toasts = std::min(\
		{ mlAvail / (nl*n), slicesAvail / n, p / (np*n) });
	
	printf("%d", toasts);
	
	return 0;
}
