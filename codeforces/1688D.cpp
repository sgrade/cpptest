// D. The Enchanted Forest
// NOT FINISHED

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int &el: a) cin >> el;

        long long ans = 0;

        int x = k / n;
        int rem = k % n;
       
        ans = (n * (n - 1) / 2) * x;

        if (x > 0) {
            ans += accumulate(a.begin(), a.end(), 0LL);
            ans += rem * (rem - 1) / 2;
        }

        else {
            int left = 0, right = left + rem;
            long long mx = accumulate(a.begin(), a.begin() + right, 0LL);
            while (right < n) {
                int tmp = - a[left] + a[right];
            }
        }
        

        cout << ans << '\n';
    }

    return 0;
}
