// C. Inversion Graph

#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> p(n + 1);
        for (int i = 1; i < n + 1; ++i) {
            cin >> p[i];
        }

        int ans = 0;
        
        int mx = 0;
        for (int i = 1; i < n + 1; ++i) {

            // Idea = https://codeforces.com/contest/1638/submission/146365037
            mx = max(mx, p[i]);

            // If i == mx, then there is i numbers in the segment and i is the max
            // So, this is one segment
            if (i == mx) ++ans;
        }

        cout << ans << '\n';
    }

    return 0;
}
