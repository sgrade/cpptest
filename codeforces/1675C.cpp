// C. Detective Task

#include <iostream>
#include <string>
#include <algorithm>

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

        int ans = 0;

        if (n == 1 || s[0] == '0') {
            ans = 1;
        }

        else {

            int zeroes = count(s.begin(), s.end(), '0');
            size_t idx;

            if (zeroes >= 1) {
                
                idx = s.find_first_of('0');

                idx = s.find('0');

                int i;
                for (i = idx; i > -1; --i) {
                    if (s[i] == '1') {
                        break;
                    }
                }
                ans = idx - i;
                if (i != -1) ++ans;
            }

            else {
                idx = s.find_last_of('1');

                if (idx == string::npos) {
                    ans = n;
                }

                else {
                    ans = n - idx;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
