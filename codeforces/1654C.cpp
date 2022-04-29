// C. Alice and the Cake

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;


// Floor, Ceiling
ll f, c;

inline void split (ll &w) {
    f = w / 2;
    c = f;
    if (w % 2 != 0) ++c;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        ll sum = 0;
        for (int &el: a) {
            cin >> el;
            sum += el;
        }

        sort(a.begin(), a.end(), greater<int>());

        bool ans = true;

        // Editorial - https://codeforces.com/blog/entry/100127
        // Some ideas from https://codeforces.com/contest/1654/submission/150236633

        priority_queue<ll> q;
        q.push(sum);

        ll x;
        int i = 0;
        while (i < n) {

            x = q.top();
            q.pop();

            if (x < a[i]) {
                ans = false;
                goto ANS;
            }

            if (x == a[i]) {
                ++i;
                continue;
            }

            split(x);
            q.push(c);
            q.push(f);
        }

        ANS:
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
