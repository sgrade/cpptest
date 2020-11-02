// Greatest Common Factor - GCF
// same as 
// Greatest Common Divisor - GCD


#include <iostream>

using namespace std;


unsigned long long gcd(unsigned long long a, unsigned long long b) { 
	if (b == 0) {
		return a;
	} 
	return gcd(b, a % b);  
}


int main() { 
   
   unsigned long long a = 18;
   unsigned long long b = 30;

   cout << gcd(a, b) << endl;

   return 0; 
}
