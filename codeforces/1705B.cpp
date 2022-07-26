// B. Mark the Dust Sweeper

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
        for (int &el: a) 
            cin >> el;

        long long ans = 0;

        int i = 0;
        int zeroes = 0;

        while (a[i] == 0) {
            ++i;
        }

        for (; i < n - 1; ++i) {
            ans += a[i];
            if (a[i] == 0) {
                ++ans;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
