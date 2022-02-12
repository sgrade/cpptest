// A. Sorting Parts

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

        bool ans = is_sorted(begin(a), end(a));

        cout << (ans ? "NO" : "YES") << '\n';
    }

    return 0;
}
