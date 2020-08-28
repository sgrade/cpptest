// A. Die Roll

#include <stdio.h>
#include <algorithm>


// greatest common factor
int gcf(int a, int b){
	
	// cout << "a: " << a << " b: " << b << endl;
	if (a < b) std::swap(a, b);
	if (a%b == 0) return b;
	return gcf(a%b, b);
	
}

int main(){
	
	int y, w;
	scanf("%d %d", &y, &w);
	
	if (y < w) std::swap (y, w);
	// printf("%d %d\n", y, w);
	
	// +1 because Y and W are true gentlemen
	int a = 6-y+1;
	// printf("%d\n", a);
	int gcfAB = gcf(a, 6);
	
	int A = a/gcfAB;
	int B = 6/gcfAB;
	
	printf("%d/%d", A, B);
	
	return 0;
}
