// B. Sifid and Strange Subsequences
// Wrong answer on pretest 2

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        int tmp;
        vector<int> a(n);
        map<int, int, greater<int>> mp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            a[i] = tmp;
            ++mp[tmp];
        }

        int ans = mp.size();
        if (mp[0] > 0) {
            ans += mp[0] - 1;
        }
        
        auto it = begin(mp);
        for (int x = 0; x < mp.size(); ++x) {
            int MAX = it->first;
            for (int j = n-1; j > 0; --j) {
                for (int i = j-1; i > -1; --i) {
                    if (i == j || (a[i] == a[j] && a[i] != 0)) {
                        continue;
                    }
                    if (abs(a[i] - a[j]) < MAX) {
                        ans -= it->second;
                        goto OUTER;
                    }
                }
            }
            OUTER:
                ++it;
        }

        cout << ans << endl;
    }

    return 0;
}
