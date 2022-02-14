// A. Reverse

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

        vector<int> p(n+1);
        for (int i = 1; i < n+1; ++i) {
            cin >> p[i];
        }

        vector<int> output;
        int i = 1;
        while (i < n+1 && p[i] == i) {
            output.push_back(i);
            ++i;
        }

        if (size(output) != n) {
            auto it = find(begin(p), end(p), i);
            reverse(begin(p) + i, it + 1);
            for (; i < n+1; ++i) {
                output.push_back(p[i]);
            }
        }

        for (auto &el: output) {
            cout << el << ' ';
        }
        cout << '\n';
    }

    return 0;
}
