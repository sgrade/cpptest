// C. Division by Two and Permutation

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

        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &el: a) {
            cin >> el;
        }
        sort(begin(a), end(a), greater<int>());

        bool ans = true;

        // Editorial - https://codeforces.com/blog/entry/98942
        
        vector<bool> found(n+1);

        int tmp;
        for (int i = 0; i < n; ++i) {
            
            tmp = a[i];

            while (tmp > n || found[tmp]) {
                tmp /= 2;
            }

            if (tmp > 0) {
                found[tmp] = true;
            }
            else {
                ans = false;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }


    return 0;
}
