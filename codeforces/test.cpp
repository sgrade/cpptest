#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
const int INF = 2e9 + 1;
 
ll getS(ll x) {
    return x * (x + 1) / 2; 
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T --> 0) {
        ll x;
        cin >> x;
        int ans = 0;
        for (int i = 1; getS((1LL << i) - 1) <= x; i++) {
            ans++;
            x -= getS((1LL << i) - 1);
			cout << getS((1LL << i) - 1) << endl;
        }
        cout << ans << '\n';
    }
    return 0;
}