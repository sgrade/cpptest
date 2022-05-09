// A. Direction Change

#include <iostream>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        int ans;

        if (n == 1 && m == 1) ans = 0;

        else if (max(n, m) == 2 && min(n, m) == 1) ans = 1;
        
        else if (n == 1 || m == 1) ans = -1;

        else {
            // https://codeforces.com/contest/1668/submission/154079353
            ans = min(n, m) * 2 + (max(n, m) - min(n, m)) * 2 - 2 - (n % 2 != m % 2);
        }

        cout << ans << '\n';
    }

    return 0;
}
