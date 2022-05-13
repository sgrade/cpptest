// C. Binary String
// NOT FINISHED

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        int n = s.size();

        int zeroes = count(s.begin(), s.end(), '0');
        int ones = n - zeroes;

        int ans = zeroes;

        int l1, r1, l0, r0;
        int l_count, r_count;
        int ones_deleted = 0;
        while (ones > 0) {

            l1 = s.find('1');
            r1 = s.rfind('1');

            zeroes -= l1 + (n - 1 - r1);
            ans = zeroes;

            if (zeroes == 0 || l1 >= r1) {
                goto ANS;
            }

            l_count = 1, r_count = 1;
            while (l1 <= r1) {
                
                l0 = l1;
                while (l0 != string::npos && s[l0] != '0') {
                    ++l_count;
                    ++l0;
                }
                l1 = l0;
                while (l1 != string::npos && s[l1] != '1') {
                    --l_count;
                    ++l1;
                }
                if (l1 == string::npos) {
                    goto ANS;
                }

                r0 = r1;
                while (r0 > l1 && s[r0] != '0') {
                    ++r_count;
                    --r0;
                }
                r1 = r0;
                while (r1 > l1 && s[r1] != '1') {
                    --r_count;
                    --r1;
                }
                if (r1 <= l1) {
                    goto ANS;
                }
            }

        }

        ANS:
        cout << ans << '\n';
    
    }

    return 0;
}
