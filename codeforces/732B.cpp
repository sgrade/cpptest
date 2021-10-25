// B. Cormen — The Best Friend Of a Man

#include <iostream>
#include <vector>

using namespace std;


int main() {

        int n, k;
        cin >> n >> k;

        vector<int> a(n+1);
        a[0] = k;

        for (int i = 1; i < n+1; ++i) {
            cin >> a[i];
        }

        int ans = 0;
        vector<int> b(n+1);
        b[0] = k;

        int need;
        for (int i = 1; i < n+1; ++i) {
            need = max(k - (b[i-1] + a[i]), 0);
            ans += need;
            b[i] = a[i] + need;
        }

        cout << ans << endl;
        for (int i = 1; i < n+1; ++i) {
            cout << b[i] << ' ';
        }
        cout << endl;

    return 0;
}
