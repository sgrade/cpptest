// C. Detective Task
// NOT FINISHED

#include <iostream>
#include <string>
#include <vector>
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

        if (n == 1 || s[0] == 0) {
            ans = 1;
        }

        else {

            size_t first_not_one = s.find_first_not_of('1');
            
            if (first_not_one == 0) ans = 0;
            else ans = 1;
            
            size_t next_zero = s.find_first_of('0', first_not_one + 1);
            if (next_zero != string::npos) {
                int cnt = 0;
                for (int i = next_zero; i > -1; --i) {
                    ++cnt;
                    if (s[i] != '?') break;
                }
                ans += cnt;
            }

            else {
                int cnt = 0;
                for (int i = n-1; i > -1; --i) {
                    ++cnt;
                    if (s[i] != '?') break;
                }
                ans += cnt;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
