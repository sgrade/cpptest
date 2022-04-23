// C. Unequal Array

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

        int ans = 0;

        if (n > 2) {

            int first = -1, last = -1;

            for (int i = 0; i < n - 1; ++i) {
                if (a[i] == a[i+1]) {
                    first = i + 1;
                    break;
                }
            }

            for (int i = n - 2; i > first; --i) {
                if (a[i] == a[i+1]) {
                    last = i;
                    break;
                }
            }

            if (last == -1) {
                if (a[first-1] == a[first+1]) ++ans;
            }

            else {
                ans = last - first;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
