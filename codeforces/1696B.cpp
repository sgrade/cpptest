// B. NIT Destroys the Universe

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

        int n;
        cin >> n;

        vector<int> a(n);
        for (int &el: a) cin >> el;

        int ans = 0;

        bool all_not_zeroes_together = true;
        int left = -1, right = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] != 0) {
                left = i;
                break;
            }
        }
        for (int i = n - 1; i > -1; --i) {
            if (a[i] != 0) {
                right = i;
                break;
            }
        }
        if (left != -1) {
            for (int i = left; i <= right; ++i) {
                if (a[i] == 0) {
                    all_not_zeroes_together = false;
                }
            }
        }

        sort(a.begin(), a.end());
        
        if (a[0] == 0 && a[n - 1] == 0) {
            ans = 0;
        }

        else if (a[0] != 0) {
            ans = 1;
        }
        
        else {
            if (all_not_zeroes_together) {
                ans = 1;
            }
            else {
                ans = 2;
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}
