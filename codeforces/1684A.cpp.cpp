// A. Digit Minimization

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

        vector<int> a;
        while (n > 0) {
            a.push_back(n % 10);
            n /= 10;
        }

        int ans;
        if (a.size() > 2) {
            ans = *min_element(a.begin(), a.end());
        }
        else {
            ans = a[0];
        }

        cout << ans << '\n';
    }

    return 0;
}
