// B. Game of Ball Passing

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (int &el: a) {
            cin >> el;
        }

        sort(begin(a), end(a));

        ll ans = 0;
        
        // Editorial - https://codeforces.com/blog/entry/100592
        ll sum = accumulate(begin(a), end(a), 0LL);

        if (sum > 0) {
            sum -= a[n-1];
            ll gap = a[n-1] - sum;
            ans = gap < 2 ? 1 : gap;
        }

        cout << ans << '\n';
    }

    return 0;
}
