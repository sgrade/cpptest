// A. Working Week
// Wrong answer on pretest 2

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

        n -= 4;
        
        int l1 = 1, l2 = 1, l3 = n - l2;

        int ans = min({abs(l1 - l2), abs(l2 - l3), abs(l1 - l3)});
        
        int current_ans, mid;

        int diff = n / 3;
        if (diff > 0) {
            diff += n % 3;
        }

        int x;
        for (int i = 0; i <= diff; ++i) {
            x = l2 + i;
            l3 = n - x;
            current_ans = min(abs(l1 - x), abs(x - l3));
            ans = max(ans, current_ans);
        }

        cout << ans << '\n';
    }

    return 0;
}
