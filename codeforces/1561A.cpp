// A. Simply Strange Sort

#include <iostream>
#include <algorithm>
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

        int ans = 0;

        int i = 1;
        while (true) {

            if (is_sorted(begin(a), end(a))) {
                break;
            }

            ++ans;

            int j;
            if (i % 2 != 0) {
                j = 1;
                for (; j <= n-2; j += 2) {
                    if (a[j-1] > a[j]) {
                        swap(a[j-1], a[j]);
                    }
                }
            }
            else {
                j = 2;
                for (; j <= n-1; j += 2) {
                    if (a[j-1] > a[j]) {
                        swap(a[j-1], a[j]);
                    }
                }
            }

            ++i;
        }

        cout << ans << endl;

    }

    return 0;
}
