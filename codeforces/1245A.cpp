// A. Good ol' Numbers Coloring

#include <iostream>
#include <algorithm>

using namespace std;


int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}


int main(){

    int t;
    cin >> t;

    while(t--){

        int a, b;
        cin >> a >> b;

        // Editorial - https://codeforces.com/blog/entry/71080
        if (gcd(a, b) == 1) cout << "Finite" << endl;
        else cout << "Infinite" << endl;

    }

    return 0;
}
