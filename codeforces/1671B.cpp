// B. Consecutive Points Segment

#include <iostream>
#include <vector>

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
        for (int &el: a) cin >> el;

        bool ans = true;

        int d = 1;
        bool moved_right = false, moved_left = false;
        for (int i = 1; i < n; ++i) {
            d = a[i] - a[i-1];
            if (d > 1) {
                if (moved_right == false) {
                    moved_right = true;
                    ++a[i-1];
                }
                d = a[i] - a[i-1];
                if (d > 1) {
                    if (moved_left == false) {
                        moved_left = true;
                        --a[i];
                        d = a[i] - a[i-1];
                        if (d > 1) {
                            ans = false;
                            break;
                        }
                    }
                    else {
                        --a[i];
                        d = a[i] - a[i-1];
                        if (d > 1) {
                            ans = false;
                            break;
                        }
                    }
                }
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
