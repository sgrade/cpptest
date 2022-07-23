// A. Another String Minimization Problem

#include <iostream>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        string s(m, 'B');

        int x, mn, mx;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            --x;
            mn = min(x, m - x - 1);
            mx = max(x, m - x - 1);
            if (s[mn] != 'A') {
                s[mn] = 'A';
            }
            else {
                s[mx] = 'A';
            }
        }
        
        cout << s << '\n';
    }

    return 0;
}
