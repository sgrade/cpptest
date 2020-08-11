//A. Design Tutorial: Learn from Math

#include <iostream>
#include <math.h>       /* sqrt */

using namespace std;

bool checkComposite(const int &c){
	
	// cout << "Checking if composite: " << c << endl;
	
	// 1 is not prime, not composite
	// 2,3 - prime (not composite)
	if (c<=3) return false;
	
	// if divisible by two, by definition it is not prime - composite
	if (c%2==0) return true;
	
	// Priznaki sostavnogo chisla
	// https://scienceland.info/algebra8/prime-numbers-properties
	int tmp=sqrt(c);
	// cout << "Sqrt: " << tmp << endl;
	while(tmp>2){
		// cout << tmp << endl;
		if (c%tmp == 0) return true;
		--tmp;
	}
	
	return false;
}

int main(){
	
	int n, x;
	scanf("%d", &n);
	
	x = n/2;
	while(x>3){
		bool composite = checkComposite(x) && checkComposite(n-x);
		// cout << composite << endl;
		if (composite) break;
		--x;
	}
	
	cout << x << " " << n-x;
	
	return 0;
}
