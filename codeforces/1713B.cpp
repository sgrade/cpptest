// B. Optimal Reduction
// Wrong answer on pretest 2

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
        
        for (int i = 1; i < n - 1; ++i) {
            if (a[i - 1] > a[i] && a[i] < a[i + 1]) {
                ans = false;
                break;
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
