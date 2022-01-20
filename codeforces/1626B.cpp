// B. Minor Reduction

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        string x;
        cin >> x;

        int n = size(x);
        vector<int> ans(n);

        for (int i = 0; i < n; ++i) {
            ans[i] = x[i] - '0';
        }

        int i, sm = 0;
        bool found = false;
        for (i = n - 2; i > -1; --i) {
            sm = ans[i] + ans[i+1];
            if (sm > 9) {
                found = true;
                ans[i] = 1;
                ans[i+1] = sm - 10;
                break;
            }
        }

        if (!found) {
            ans[1] = ans[0] + ans[1];
            ans[0] = 0;
            i = 1;
        }
        else {
            i = 0;
        }

        for (; i < n; ++i) {
            cout << ans[i];
        }

        cout << '\n';
    }

    return 0;
}
