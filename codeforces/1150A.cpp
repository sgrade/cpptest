// A. Stock Arbitraging

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int n, m, r;
    cin >> n >> m >> r;

    int s[n], b[m];
    for (auto &el: s) cin >> el;
    for (auto &el: b) cin >> el;
    sort(s, s+n);
    sort(b, b+m);

    int ans = r / s[0] * b[m-1] + r % s[0];
    if (ans < r) ans = r;
    cout << ans << endl;

    return 0;
}