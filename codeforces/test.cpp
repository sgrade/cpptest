
#include <iostream>
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

void tst(int a){
	cout << a << endl;
	if (a<0){
		cout << "Returning!" << endl;
		return;
	}
	return tst(a-1);
}

int main(){
	
	tst(5);
	
}
