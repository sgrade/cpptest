// B. GCD Problem

#include <iostream>
#include <numeric>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        int a, b, c = 1;
        
        // Editorial - https://codeforces.com/blog/entry/97920
        for (a = 2; a < n; ++a) {
            b = n - 1 - a;
            if (gcd(a, b) == 1) {
                break;
            }
        }

        cout << a << ' ' << b << ' ' << c << endl;
    }

    return 0;
}
