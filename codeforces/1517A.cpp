// A. Sum of 2050

#include <iostream>
#include <string>

using namespace std;
using ull = unsigned long long;


ull check(ull x, int len, ull num) {
    
    if (len < 4) {
        return 0ULL;
    }

    ull tmp = 205;
    while (tmp * 10 <= x) {
        tmp *= 10;
    }

    num += x / tmp;
    ull rem = x % tmp;
    if (rem != 0) {
        len = to_string(rem).size();
        num = check (rem, len, num);
    }
    
    return num;
}

int main() {

    int t;
    cin >> t;

    while (t--) {

        ull n;
        cin >> n;

        ull ans = 0;

        if (n >= 2050 && n % 50 == 0) {
            string s = to_string(n);
            int len = s.size();
            ans = check(n, len, 0);
        }


        if (ans > 0) {
            cout << ans << endl;
        }
        else {
            cout << "-1" << endl;
        }
    }

    return 0;
}
