// A. Parkway Walk

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

        vector<int> a(n + 1);
        for (int i = 1; i < n + 1; ++i) {
            cin >> a[i];
        }

        int ans = -m;
        
        int d;
        for (int i = 1; i < n + 1; ++i) ans += a[i];
        
        cout << max(0, ans) << '\n';
    }

    return 0;
}
