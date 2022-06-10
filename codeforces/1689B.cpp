// B. Mystic Permutation

#include <iostream>
#include <algorithm>
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

        vector<pair<int, int>> p(n);
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            p[i] = pair<int, int>(tmp, i);
        }

        if (n == 1) {
            cout << "-1\n";
            continue;
        }

        sort(p.begin(), p.end());

        vector<int> q(n);
        
        for (int i = 0; i < n - 1; ++i) {
            if (p[i].second == i) {
                swap(p[i], p[i+1]);
            }
            q[i] = p[i].first;
        }
        q[n - 1] = p[n - 1].first;
        if (p[n - 1].second == n - 1) {
            swap(q[n - 1], q[n - 2]);
        }

        for (int &el: q) cout << el << ' ';
        cout << '\n';
    }

    return 0;
}
