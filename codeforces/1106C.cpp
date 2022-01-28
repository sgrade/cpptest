// C. Lunar New Year and Number Division

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &el: a) {
        cin >> el;
    }
    sort (begin(a), end(a));

    ll ans = 0;

    int x;
    for (int i = 0; i < n/2; ++i) {
        x = a[i] + a[n-i-1];
        ans += x * x;
    }
    
    cout << ans << '\n';

    return 0;
}
