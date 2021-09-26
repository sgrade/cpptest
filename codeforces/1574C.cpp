// C. Slay the Dragon
 
#include <iostream>
#include <set>
#include <vector>
#include <limits>
 
using namespace std;
using ll = long long;
 
 
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;
 
    ll tmp, sm = 0;
    set<ll> a;
 
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        a.insert(tmp);
        sm += tmp;
    }
 
    vector<ll> v;
    for (auto &el: a) {
        v.push_back(el);
    }
    vector<ll>::iterator it;
 
    int m;
    cin >> m;
 
    ll def, att;
    int idx;
    for (int i = 0; i < m; ++i) {
        cin >> def >> att;
 
        ll ans = numeric_limits<ll>::max();
 
        it = lower_bound(begin(v), end(v), def);
        idx = distance(begin(v), it);
 
        // Editorial - https://codeforces.com/blog/entry/95188
 
        if (idx > 0) {
            ans = min(ans, def - v[idx-1]) + max(0LL, att - (sm - v[idx-1]));
        }
        
        if (idx < size(v)){
            ans = min(ans, max(0LL, att - (sm - v[idx])));
        }
 
        cout << ans << endl;
    }
 
    return 0;
}
