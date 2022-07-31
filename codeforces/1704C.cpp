// C. Virus

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

        int n, m;
        cin >> n >> m;

        vector<int> a(m);
        for (int &el: a) cin >> el;
        sort(a.begin(), a.end());

        vector<int> v;
        int d = (a[0] - 1) + (n - a[m - 1]);
        v.emplace_back(d);
        for (int i = 1; i < m; ++i) {
            d = a[i] - a[i - 1] - 1;
            v.emplace_back(d);
        }
        sort(v.begin(), v.end(), greater<int>());

        int healthy = 0;
        int infected = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] - infected < 1) {
                break;
            }
            healthy += max(1, v[i] - infected - 1);
            infected += 4;
        }

        int ans = n - healthy;

        cout << ans << '\n';
    }

    return 0;
}
