// C. LIS or Reverse LIS?

#include <iostream>
#include <map>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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

        int ans = 0;

        // Editorial - https://codeforces.com/blog/entry/103097
        int x = 0;
        for (const auto &[key, value]: cnt) {
            if (value > 1) ++ans;
            else ++x;
        }

        ans += (x + 2 - 1) / 2;

        cout << ans << '\n';
    }

    return 0;
}
