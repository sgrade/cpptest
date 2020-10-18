// C. Lucky Numbers

#include <iostream>
#include <math.h>

using namespace std;


int main(){

    unsigned long long n;
    cin >> n;

    // n = 1: two ways to choose (7, 8)
    // n = 2: four ways to choose (77, 78, 87, 88)
    // total: (n1 + n2) = 6
    
    // Basic combinatoric rules
    // Rus: http://cito-web.yspu.org/link1/metod/theory/node4.html
    // Eng: https://www.hackerearth.com/practice/math/combinatorics/basics-of-combinatorics/tutorial/

    // Geometric series (the sum of the numbers in a geometric progression):
    // (a * (1 - 2^n)) / (1 - 2)
    // References:
    // https://en.wikipedia.org/wiki/Geometric_progression#Geometric_series

    // pow's precision is not good enough, so use powl
    // https://en.cppreference.com/w/cpp/numeric/math/pow

    unsigned long long ans = 2 * (powl(2, n) - 1);
    
    cout << ans << endl;

    return 0;
}