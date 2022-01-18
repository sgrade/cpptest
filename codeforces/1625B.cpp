// B. Elementary Particles

#include <iostream>
#include <vector>
#include <map>
#include <limits>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int inf = numeric_limits<int>::max();

    int t;
    cin >> t;

    while (t--) {
        
        int n;
        cin >> n;

        // Editorial - https://codeforces.com/blog/entry/99031

        int distance = inf;

        map<int, int> mp;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            if (mp.find(tmp) != mp.end()) {
                distance = min(distance, i - mp[tmp]);
            }
            mp[tmp] = i;
        }

        int ans = distance == inf ? -1 : n - distance;

        cout << ans << '\n';
    }

    return 0;
}
