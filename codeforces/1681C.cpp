// C. Double Sort

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

        vector<int> a(n), b(n);
        for (int &el: a) cin >> el;
        for (int &el: b) cin >> el;

        // Editorial - https://codeforces.com/blog/entry/103163
        // Explanation - https://www.youtube.com/watch?v=UvyMHHl9E24.

        vector<int> a_sorted(a.begin(), a.end());
        sort(a_sorted.begin(), a_sorted.end());
        vector<int> b_sorted(b.begin(), b.end());
        sort(b_sorted.begin(), b_sorted.end());
        
        bool ans = true;

        vector<pair<int, int>> output;

        bool swapped = false;
        for (int i = 0; i < n; ++i) {
            if (a[i] == a_sorted[i] && b[i] == b_sorted[i]) continue;
            else {
                for (int j = i + 1; j < n; ++j) {
                    if (a[j] == a_sorted[i] && b[j] == b_sorted[i]) {
                        swap(a[i], a[j]);
                        swap(b[i], b[j]);
                        output.emplace_back(pair<int, int>(i + 1, j + 1));
                    }
                }
            }
            if (a[i] == a_sorted[i] && b[i] == b_sorted[i]) continue;
            else {
                ans = false;
                break;
            }
        }

        if (ans) {
            cout << output.size() << '\n';
            if (output.size() > 0) {
                for (const auto &p: output) {
                    cout << p.first << ' ' << p.second << '\n';
                }
            }
        }
        else {
            cout << "-1\n";
        }
    }

    return 0;
}
