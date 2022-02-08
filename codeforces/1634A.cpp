// A. Reverse and Concatenate

#include <iostream>
#include <string>
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

        string s;
        cin >> s;

        string rev = string(rbegin(s), rend(s));

        int ans = 1;

        if (s != rev && k != 0) {
            ans = 2;
        }

        cout << ans << '\n';
    }

    return 0;
}
