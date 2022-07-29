// D. Black and White Stripe

#include <iostream>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int left = 0, right = 0;
        int white = 0;

        while (right < k && right < n) {
            if (s[right] == 'W') {
                ++white;
            }
            ++right;
        }

        int ans = white;

        int cur_ans;
        while (right < n) {
            if (s[right] == 'W') {
                ++white;
            }
            
            if (s[left] == 'W') {
                --white;
            }

            cur_ans = white;
            ans = min(ans, cur_ans);

            ++left;
            ++right;
        }

        cout << ans << '\n';
    }

    return 0;
}
