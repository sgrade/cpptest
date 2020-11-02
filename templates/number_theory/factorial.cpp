// Factorial

#include <iostream>
#include <algorithm>	// std::swap

using namespace std;


unsigned long long fact(unsigned long long n){
    unsigned long long factorial = 1;
    for (unsigned long long i=1; i<=n; ++i){
        factorial *= i;
    }
    return factorial;
}


int main(){
	
	unsigned long long num = 4;
    cout << fact(num) << endl;
	
}
