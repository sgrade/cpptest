// B. Margarite and the best present

#include <iostream>

using namespace std;
using ll = long long;


ll sm(ll x) {
    if (x % 2 == 0) {
        return x / 2;
    }
    else {
        return -x + sm(x-1);
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        
        int l, r;
        cin >> l >> r;

        // Editorial - https://codeforces.com/blog/entry/63436
        int ans = sm(r) - sm(l-1);

        cout << ans << '\n';

    }

    return 0;
}