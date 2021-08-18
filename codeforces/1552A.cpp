// A. Subsequence Permutation

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<char> v(begin(s), end(s));
        sort(begin(v), end(v));

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != v[i]) {
                ++ans;
            }
        }

        cout << ans << endl;

    }

    return 0;
}
