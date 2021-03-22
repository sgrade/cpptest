// B. M-arrays

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int tmp;
        map<int, int> mp;
        for (int i = 0; i < n; ++i)
        {
            cin >> tmp;
            ++mp[tmp];
        }

        int ans = 0;

        if (n == 1)
        {
            ans = 1;
        }
        else
        {
            // Editorial - https://codeforces.com/blog/entry/88677
            map<int, int> mods;
            for (auto &el: mp) {
                mods[el.first % m] += el.second;
            }

            if (mods.find(0) != mods.end()) {
                ++ans;
                mods.erase(0);
            }
            
            if (m % 2 == 0 && mods.find(m / 2) != mods.end()) {
                ++ans;
                mods.erase(m / 2);
            }

            int x, y, mn, mx;
            for (auto el: mods) {
                x = el.first;
                y = m-x;
                
                if (2 * x < m || mods.find(y) == mods.end()) {
                    ans += 1;

                    mn = min(mods[x], mods[y]);
                    mx = max(mods[x], mods[y]);
                    if (mx - mn > 1) {
                        ans += mx - mn - 1;
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
