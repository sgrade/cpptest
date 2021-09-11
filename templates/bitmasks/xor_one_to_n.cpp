// C++ program to find XOR of numbers
// from 1 to n.

#include <iostream>

using namespace std;

 
// Method to calculate xor
int computeXOR(int n) {
    // Source - https://www.geeksforgeeks.org/calculate-xor-1-n/
   
    // If n is a multiple of 4
    if (n % 4 == 0) {
        return n;
    }
 
    // If n%4 gives remainder 1
    if (n % 4 == 1) {
        return 1;
    }
    
    // If n%4 gives remainder 2
    if (n % 4 == 2) {
        return n + 1;
    }
 
    // If n%4 gives remainder 3
    return 0;
}
 

int main() {
    int n = 5;
    cout << computeXOR(n) << endl;
}