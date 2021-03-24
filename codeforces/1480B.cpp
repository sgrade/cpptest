// B. The Great Hero

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;


int main() {

    int t;
    cin >> t;

    while (t--) {

        ll A, B, n;
        cin >> A >> B >> n;

        vector<ll> a(n), b(n);
        for (auto &el: a) {
            cin >> el;
        }
        for (auto &el: b) {
            cin >> el;
        }

        bool ans = false;
        
        ll fights;
        for (int i = 0; i < n; ++i) {
            fights = (b[i] + A - 1) / A;
            B -= fights * a[i];
        }
        
        if (B + *max_element(a.begin(), a.end()) > 0) {
            ans = true;
        }

        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
