// Restore Modulo
// Wrong answer on test 2

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

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

        // Editorial - https://codeforces.com/blog/entry/88963

        int ans = 0;
        int m = 0, c, s;

        if (n > 1) {

            int diff, zero_diff_count = 0, pos_diff_count = 0, neg_diff_count = 0;
            set<int> pos_diff, neg_diff;

            for (int i = 1; i < n; ++i) {
                diff = a[i] - a[i-1];
                if (diff == 0) {
                    ++zero_diff_count;
                }
                else if (diff > 0) {
                    ++pos_diff_count;
                    pos_diff.insert(diff);
                }
                else {
                    ++neg_diff_count;
                    neg_diff.insert(diff);
                }
            }

            // Editorial: "Handle the case of 𝑐=0 separately."
            if (zero_diff_count > 0) {
                if (zero_diff_count == n - 1) {
                    ans = 0;
                }
                else {
                    ans = -1;
                }
            }

            // Editorial: "Ok, now 𝑐≠0 and no two consecutive numbers coincide."
            else {
                if (pos_diff.size() > 1 || neg_diff.size() > 1) {
                    ans = -1;
                }
                else {
                    ans = 1;
                    m = *pos_diff.begin() - *neg_diff.begin();
                    if (pos_diff.size() > 0) {
                        c = *pos_diff.begin();
                    }
                    else {
                        c = *neg_diff.begin();
                    }

                    // Check
                    if (a[0] >= m) {
                        ans = -1;
                    }
                    else {
                        for (int i = 1; i < n; ++i) {
                            if (a[i] != (a[i-1] + c) % m) {
                                ans = -1;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if (ans == 0 || ans == -1) {
            cout << ans << endl;
        }
        else {
            cout << m << ' ' << c << endl;
        }

    }

    return 0;
}
