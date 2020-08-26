// A. Epic Game

#include <stdio.h>


//https://www.tutorialspoint.com/cplusplus-program-to-find-gcd
int gcd (int a, int b) {
	if (b==0) return a;
	return gcd(b, a%b);
}

int main(){
	
	int a, b, n;
	scanf("%d %d %d\n", &a, &b, &n);
	
	int flag = 0;
	int stonesToRemove = 0;
	while (stonesToRemove <= n){
		
		if (flag == 0){
			stonesToRemove = gcd(a, n);
		}
		else stonesToRemove = gcd(b, n);
		
		// printf("%d %d %d\n", flag, n, stonesToRemove);
				
		n -= stonesToRemove;
						
		flag = !flag;
		
		
	}
	
	printf("%d\n", !flag);
	
	return 0;
}
