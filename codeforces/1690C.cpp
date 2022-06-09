// C. Restoring the Duration of Tasks

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

        vector<int> s(n);
        for (int &el: s) cin >> el;

        vector<int> f(n);
        for (int &el: f) cin >> el;

        cout << f[0] - s[0] << ' ';
        for (int i = 1; i < n; ++i) {
            cout << f[i] - max(s[i], f[i-1]) << ' ';
        }
        cout << '\n';
    }

    return 0;
}
