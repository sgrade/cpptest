// A. Happy Birthday, Polycarp!

#include <iostream>
#include <set>

using namespace std;


int main() {

    int t;
    cin >> t;

    set<long long> dp;
    for (int i = 1; i < 10; ++i) {
        long long x = i;
        while (true) {
            dp.insert(x);
            if (x < 1e9) {
                x *= 10;
                x += i;
            }
            else {
                break;
            }
        }
    }

    while (t--) {

        int n;
        cin >> n;

        int ans = 0;

        set<long long>::iterator it = begin(dp);
        while (*it <= n) {
            ++ans;
            ++it;
        }

        cout << ans << '\n';
    }

    return 0;
}
