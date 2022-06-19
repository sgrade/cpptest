// A. Optimal Path

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

        long long ans = (1 + 1LL * (m - 1)) * (m - 1) / 2;;
        
        ans += (2 * m + 1LL * m * (n - 1)) * n / 2;

        cout << ans << endl;
    }

    return 0;
}
