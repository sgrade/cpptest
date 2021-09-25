// C. Fadi and LCM

#include <iostream>
#include <math.h>
#include <numeric>

using namespace std;
using ull = unsigned long long;


int main() {

    ull x;
    cin >> x;

    // Editorial - https://codeforces.com/blog/entry/72950

    ull a, b, ans_a, ans_b;

    for (a = 1; a <= sqrt(x); ++a) {
        if (x % a == 0) {
            b = x / a;
            if (lcm(a, b) == x) {
                ans_a = a;
                ans_b = b;
            }
        }
    }

    cout << ans_a << ' ' << ans_b << endl;

    return 0;
}
