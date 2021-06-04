// A. Fair Playoff

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        vector<int> s(4);
        for (int i = 0; i < 4; ++i) {
            cin >> s[i];
        }

        vector<int> sorted(begin(s), end(s));
        sort(begin(sorted), end(sorted));

        int idx1, idx2;
        idx1 = find(begin(s), end(s), sorted[2]) - begin(s);
        idx2 = find(begin(s), end(s), sorted[3]) - begin(s);
        if (idx1 > idx2) {
            swap(idx1, idx2);
        }

        cout << (idx1 < 2 && idx2 > 1 ? "YES" : "NO") << endl;
    }

    return 0;
}
