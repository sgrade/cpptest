// A. Profitable Interest Rate

#include <bits/stdc++.h>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int a, b;
        cin >> a >> b;

        int need = b - a;
        if (need <= 0) {
            cout << a << endl;
            continue;
        }
        
        int left = 0, right = a + 1, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (a - mid >= b - mid * 2)
                right = mid;
            else
                left = mid + 1;
        }
        cout << (a - right > 0 ? a - right : 0) << endl;
    }

    return 0;
}
