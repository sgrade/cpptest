// A. Gamer Hemose

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, H;
        cin >> n >> H;

        vector<int> a(n);
        for (auto &el: a) {
            cin >> el;
        }

        sort(begin(a), end(a));

        long long ans = (H / (a[n-1] + a[n-2])) * 2;
        
        long long rem = H % (a[n-1] + a[n-2]);
        if (rem) {
            if (rem <= a[n-1]) {
                ++ans;
            }
            else {
                ans += 2;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
