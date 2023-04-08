// B. Li Hua and Pattern
// Wrong answer 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<vector<int>> a(n, vector<int>(n));
        vector<vector<int>> r(n, vector<int>(n));
        int ones = 0, zeroes;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
                r[n - 1 - i][n - 1 - j] = a[i][j];
                ones += a[i][j];
            }
        }

        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        bool stop = false;
        for (int i = 0; top < bottom && i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] != a[n - 1 - i][n - 1 - j]) {
                    stop = true;
                    break;
                }
            }
            if (stop) 
                break;
            else {
                top = i + 1;
                bottom = n - 1 - i;
            }
        }
        stop = false;
        for (int j = 0; left < right && j < n; ++j) {
            for (int i = top; i < bottom; ++i) {
                if (a[i][j] != a[n - 1 - i][n - 1 - j]) {
                    stop = true;
                    break;
                }
            }
            if (stop)
                break;
            else {
                left = j + 1;
                right = n - 1 - j;
            }
        }

        bool ans = true;

        // Scenario 0 - no need to convert
        for (int i = top; ans && (i < bottom); ++i) {
            for (int j = left; j < right; ++j) {
                if (a[i][j] != r[i][j]) {
                    ans = false;
                    break;
                }
            }
        }

        if (ans) {
            goto ANS;
        }

        // Scenario 1 - convert all to one color
        zeroes = n * n - ones;
        if (k > 0 && ((k >= ones && (k - ones) % k == 0) || (k >= zeroes && (k - zeroes) % k == 0))) {
            ans = true;
            goto ANS;
        }

        // Scenario 2 - rotate
        for (int i = top; i < bottom; ++i) {
            for (int j = left; j < right; ++j) {
                if (a[i][j] != r[i][j]) {
                    r[i][j] = a[i][j];
                    --k;
                    if (k < 0)
                        goto ANS;
                }
            }
            if (k < 0)
                goto ANS;
        }

        if (k % 2 != 0) {
            for (int i = top; i < bottom; ++i) {
                for (int j = left; j < right; ++j) {
                    if (r[i][j] != r[n - 1 - i][n - 1 - j]) {
                        --k;
                        ans = true;
                        goto ANS;
                    }
                }
                if (k < 0)
                    goto ANS;
            }
        }

        if (k % 2 == 0) {
            ans = true;
        }

        ANS:
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
