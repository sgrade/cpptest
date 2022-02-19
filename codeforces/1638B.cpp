// B. Odd Swap Sort

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

        // Editorial - https://codeforces.com/blog/entry/99942

        vector<vector<int>> a(2);
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            if (tmp % 2 == 0) {
                a[0].push_back(tmp);
            }
            else {
                a[1].push_back(tmp);
            }
        }

        bool ans = true;

        for (int x = 0; x < 2; ++x) {
            for (int i = 1; i < size(a[x]); ++i) {
                if (a[x][i-1] > a[x][i]) {
                    ans = false;
                    goto ANS;
                }
            }
        }

        ANS:
        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}
