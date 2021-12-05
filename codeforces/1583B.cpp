// B. Omkar and Heavenly Tree

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, m, tmp;
        cin >> n >> m;

        vector<bool> bb(n+1);
        bb[0] = true;

        int a, b, c;
        for (int i = 0; i < m; ++i) {
            cin >> a >> b >> c;
            bb[b] = true;
        }

        int root = distance(begin(bb), find(begin(bb), end(bb), false));
        for (int i = 1; i <= n; ++i) {
            if (i == root) {
                continue;
            }
            cout << root << ' ' << i << '\n';
        }
    }

    return 0;
}
