// A. Mocha and Math

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
        for (auto &el: a) {
            cin >> el;
        }

        int ans = a[0];

        for (int i = 1; i < n; ++i) {
            ans = ans & a[i];
        }

        cout << ans << endl;

    }

    return 0;
}
