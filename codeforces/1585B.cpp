// B. Array Eversion

#include <iostream>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int mx = 0;
        for (auto &el: a) {
            cin >> el;
            mx = max(mx, el);
        }

        int ans = 0;
        int prev = a[n-1];

        if (a[n-1] != mx) {
            for (int i = n-2; i > -1; --i) {
                if (a[i] > prev) {
                    ++ans;
                    prev = a[i];
                }
                if (a[i] == mx) {
                    break;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
