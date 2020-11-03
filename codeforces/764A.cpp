// A. Taymyr is calling you

#include <iostream>
#include <numeric>

using namespace std;


int main(){

    int n, m, z;
    cin >> n >> m >> z;
    
    // Editorial - https://codeforces.com/blog/entry/50205
    int g = gcd(n, m);
    int lcm = n * m / g;

    cout << z / lcm << endl;

    return 0;
}
