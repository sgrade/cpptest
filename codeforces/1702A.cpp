// A. Round Down the Price

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> rounds = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        int ans;

        auto it = rounds.begin();
        int x = *it;
        while (it != rounds.end()) {
            if (*it <= n) {
                x = *it;
                ++it;
                continue;
            }
            else break;
        }

        ans = n - x;
        
        cout << ans << '\n';
    }

    return 0;
}
