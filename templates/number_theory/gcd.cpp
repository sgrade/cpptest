// Greatest Common Factor - GCF
// same as 
// Greatest Common Divisor - GCD

// https://en.cppreference.com/w/cpp/numeric/gcd
// In C++ STL since C++17
// By default with g++ it will not work, because it uses c++14:
// man g++ | grep "This is the default for C++ code"
// GNU dialect of -std=c++14.  This is the default for C++ code.


#include <iostream>

using namespace std;


unsigned long long gcd(unsigned long long a, unsigned long long b) { 
	if (b == 0) {
		return a;
	} 
	return gcd(b, a % b);  
}


int main() { 
   
   unsigned long long a = 49;
   unsigned long long b = 10;

   cout << gcd(a, b) << endl;

   return 0; 
}
