// A. Circle Metro

#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;

    bool ans = false;

    if (a == b) {
        ans = true;
    }

    if (!ans) {
        int idx_a = a, idx_b = b;

        for (int i = 0; i < n; ++i) {
            if (idx_a == idx_b) {
                ans = true;
                break;
            }

            if (idx_a == x || idx_b == y) {
                break;
            }
            
            ++idx_a;
            if (idx_a > n) {
                idx_a = 1;
            }

            --idx_b;
            if (idx_b < 1) {
                idx_b = n;
            }
        }
    }
    
    cout << (ans ? "YES" : "NO") << '\n';

    return 0;
}
