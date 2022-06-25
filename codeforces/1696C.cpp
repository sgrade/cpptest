// C. Fishingprince Plays With Array
// NOT FINISHED

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
using ll = long long;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int &el: a) cin >> el;
        int k;
        cin >> k;
        vector<int> b(k);
        for (int &el: b) cin >> el;

        bool ans = false;

        ll sum1 = accumulate(a.begin(), a.end(), 0);
        ll sum2 = accumulate(b.begin(), b.end(), 0);

        if (sum1 % sum2 == 0) ans = true;

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
