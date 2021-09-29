// C. Jury Meeting

#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;


int main() {
    
    const int MOD = 998244353;

    // Idea - https://codeforces.com/contest/1569/submission/128258292
    vector<ll> fact(2e5+1);
    fact[0] = 1;
    for (int i = 1; i < 2e5+1; ++i) {
        fact[i] = fact[i-1] * i % MOD;
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        map<int, int> cnt;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            ++cnt[tmp];
        }

        ll ans = 0LL;
        
        auto rit = rbegin(cnt);
        
        int mx = rit->first;
        int mx_cnt = rit->second;
        if (mx_cnt >= 2) {
            ans = fact[n];
        }

        if (ans == 0) {
            ++rit;
            int mx_min_one = rit->first;
            int mx_min_one_cnt = rit->second;
            if (mx - mx_min_one != 1) {
                ans = 0;
            }

            else {
                // Formula from the Editorial - https://codeforces.com/blog/entry/94721
                ll bad_perms = 1;
                for (int i = 1; i <=n; ++i) {
                    if (i == mx_min_one_cnt + 1) {
                        continue;
                    }
                    bad_perms = bad_perms * i % MOD;
                }
                ans = (fact[n] - bad_perms + MOD) % MOD;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
