// A. Perfect Permutation

#include <iostream>
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

        vector<int> ans(n);

        if (n == 1) {
            ans[0] = 1;
        }
        else {
            for (int i = 2; i < n + 1; i += 2) {
                ans[i - 2] = i;
            }
            for (int i = 1; i < n + 1; i += 2) {
                ans[i] = i;
            }
            if (n % 2 != 0) {
                ans[n - 1] = n;
                swap(ans[n - 1], ans[0]);
            }
        }

        for (int &el: ans) {
            cout << el << ' ';
        }
        cout << '\n';
    }

    return 0;
}
