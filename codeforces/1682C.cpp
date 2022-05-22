// C. LIS or Reverse LIS?
// Wrong answer on pretest 2

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

        map<int, int>::iterator it = cnt.begin();
        int cur;
        bool add = true;
        while (it != cnt.end()) {
            cur = it->first;
            if (it->second == 1) {
                if (add) {
                    ++ans;
                }
                add = !add;
            }
            else {
                ++ans;
            }
            ++it;
        }

        if (!add && cnt.rbegin()->second > 1) {
            --ans;
        }

        cout << ans << '\n';
    }

    return 0;
}
