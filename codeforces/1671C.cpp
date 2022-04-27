// C. Dolce Vita

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, x;
        cin >> n >> x;

        vector<int> a;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            if (tmp > x) continue;
            a.push_back(tmp);
        }

        ll ans = 0;

        n = a.size();
        sort(a.begin(), a.end());

        ll sm = 0;

        int i;
        for (i = 0; i < n && sm + a[i] <= x; ++i) {
            sm += a[i];
        }
        --i;

        // Key ideas - https://codeforces.com/contest/1671/submission/154524890
        
        ll packs, days;
        ll base = 0;

        // Iterate through the packs from the most to least expensive
        for (; i > -1; --i) {
            
            if (x - sm >= 0) {
                // Number of days we can afford buying in all shops up to the i-th shop 
                days = (x - sm) / (i + 1) + 1;

                // Packs we buy
                packs = (i + 1) * days;

                ans += packs;

                // On that day the sm will increase 1 per day per pack for i+1 packs
                sm += packs;

                // After that day we don't buy the packs from that shop
                // So we substract that's shop contribution
                sm -= a[i] + days + base;

                // When later we increment sm, we don't need to take into 
                // account the i-th shop contribution
                base += days;
            }

            else {
                // We cannot afford buying from the i-th shop;
                sm -= a[i] + base;
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}
