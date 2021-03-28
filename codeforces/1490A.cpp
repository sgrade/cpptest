// A. Dense Array

#include <iostream>
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
        
        for (int i = 1; i < n; ++i) {
            while (a[i-1] * 2 < a[i]) {
                a[i-1] *= 2;
                ++ans;
            }
            while ((a[i-1] + 1) / 2 > a[i]) {
                a[i-1] = (a[i-1] + 1) / 2;
                ++ans;
            }
        }

        cout << ans << endl;

    }

    return 0;
}
