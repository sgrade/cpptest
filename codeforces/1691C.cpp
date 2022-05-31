// C. Sum of Substrings
// Wrong answer on pretest 2

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int ones = count(s.begin(), s.end(), '1');

        long long ans = 1LL * ones * 11;

        if (ones > 0) {

            vector<bool> placed(n);

            size_t first, last;

            if (s[n-1] == '1') {
                ans -= 10;
                placed[n - 1] = true;
            }
            else {
                last = s.find_last_of('1');
                if (last != string::npos && n - (last + 1) <= k) {
                    placed[last] = true;
                    k -= n - (last + 1);
                    ans -= 10;
                }
            }

            if (s[0] == '1' && !placed[0]) {
                ans -= 1;
            }
            else {
                first = ones == 1 ? last : s.find_first_of('1');
                if (first != string::npos && first <= k && !placed[first]) {
                    ans -= 1;
                    k -= first;
                }
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}
