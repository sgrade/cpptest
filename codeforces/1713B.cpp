// B. Optimal Reduction

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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        bool ans = true;
        
        int j;
        for (int i = 1; i < n - 1; ++i) {
            j = i;
            while (j < n - 1 && a[j] == a[j + 1]) {
                ++j;
            }
            if (j == n - 1) {
                break;
            }
            if (a[i - 1] > a[i] && a[i] < a[j + 1]) {
                ans = false;
                break;
            }
            i = j;
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
