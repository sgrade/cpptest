// A. Integer Sequence Dividing

#include <iostream>

using namespace std;


int main(){

    unsigned long long n;
    cin >> n;

    unsigned long long sum = (1+n)*n/2;
    
    cout << (sum%2 == 0 ? 0 : 1) << endl;

    return 0;
}