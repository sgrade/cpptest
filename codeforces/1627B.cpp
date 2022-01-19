// B. Not Sitting

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        
        int n, m;
        cin >> n >> m;

        // Editorial - https://codeforces.com/blog/entry/99067

        int nm = n * m;

        vector<int> dist;

        int tina_x, tina_y, rahul_x, rahul_y;
        for (rahul_y = 0; rahul_y < n; ++rahul_y) {
        
            // Ideas - https://codeforces.com/contest/1627/submission/142831351
            tina_y = (rahul_y < n / 2 ? n - 1 : 0);

            for (int rahul_x = 0; rahul_x < m; ++rahul_x) {
                tina_x = (rahul_x < m / 2 ? m - 1 : 0);
                dist.push_back(abs(tina_x - rahul_x) + abs(tina_y - rahul_y));
            }
        }

        sort(begin(dist), end(dist));

        for (int i = 0; i < n * m; ++i) {
            cout << dist[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
