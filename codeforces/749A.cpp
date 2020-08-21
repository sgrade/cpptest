// A. Bachgold Problem

#include <iostream>

using namespace std;


int main(){
	
	int n;
	scanf("%d", &n);
	
	if (n==2 || n==3){
		cout << 1 << endl << n;
		exit(0);
	}
	
	// 2 is the smallest prime number
	// so, maximum number of primes is achiavalbe: 
	// if n i even, all of them 2
	// if n is odd, then all of them are 2 and the last is 3
	int k = n/2;
	printf("%d\n", k);
	
	int last = n%2 ? 3 : 2;
	for (int i=0; i<k-1; ++i) printf("%d ", 2);
	printf("%d\n", last);
	
	return 0;
}
