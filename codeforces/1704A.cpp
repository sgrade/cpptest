// A. Two 0-1 sequences

#include <iostream>
#include <algorithm>
#include <vector>
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

        string a, b;
        cin >> a >> b;

        bool ans = true;

        if (a != b) {
            string aa = a.substr(n - m, m);
            for (int i = 1; i < m; ++i) {
                if (aa[i] != b[i]) {
                    ans = false;
                    break;
                }
            }
            
            if (ans && aa[0] != b[0]) {
                ans = false;
                for (int i = 0; i < n - m; ++i) {
                    if (a[i] == b[0]) {
                        ans = true;
                        break;
                    }
                }
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
