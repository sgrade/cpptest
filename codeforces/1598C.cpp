// C. Delete Two Elements

#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ull = unsigned long long;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        ull ans = 0;

        // Explanation - https://www.youtube.com/watch?v=IGvWJ2hcm28

        vector<ull> a(n);
        ull s = 0;
        for (auto &el: a) {
            cin >> el;
            s += el;
            el *= n;
        }

        s *= 2;

        map<ull, int> mp;
        for (auto &el: a) {
            ans += mp[s - el];
            ++mp[el];
        }

        cout << ans << endl;
    }

    return 0;
}
