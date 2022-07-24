// B. Difference of GCDs

#include <iostream>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;

        // Editorial - https://codeforces.com/blog/entry/104930

        bool ans = true;
        vector<int> output(n + 1);

        int min_multiple_of_i;
        for (int i = 1; i < n + 1; ++i) {
            min_multiple_of_i = (l + i - 1) / i;
            output[i] = min_multiple_of_i * i;
            if (output[i] > r) {
                ans = false;
                break;
            }
        }
        
        if (!ans) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (int i = 1; i < n + 1; ++i) {
            cout << output[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
