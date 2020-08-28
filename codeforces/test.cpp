
#include <iostream>
#include <algorithm>	// std::swap

using namespace std;

/*
int gcd(int a, int b) { 
	cout << "a: " << a << " b: " << b << endl;
	if (b == 0) {
		cout << "returning: " << a << endl;
		return a;
	} 
	return gcd(b, a % b);  
} 
int main() { 
   int a = 5, b = 6; 
   int g = gcd(a, b);
   cout<<"GCD of "<< a <<" and "<< b <<" is "<< g << endl; 
   return 0; 
}
*/

// ========================
// greatest common factor
int gcf(int a, int b){
	
	// cout << "a: " << a << " b: " << b << endl;
	if (a < b) swap(a, b);
	if (a%b == 0) return b;
	return gcf(a%b, b);
	
}

int main(){
	
	printf("%d", gcf(18, 30));
	
}
