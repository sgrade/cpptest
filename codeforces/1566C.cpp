// C. MAX-MEX Cut

#include <iostream>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s1, s2;
        cin >> s1 >> s2;

        int ans = 0;

        // Editorial - https://codeforces.com/blog/entry/94803

        bool one_found = false, zero_found = false;
        for (int i = 0; i < n; ++i) {
            
            if (s1[i] != s2[i]) {
                ans += 2;
                one_found = false;
                zero_found = false;
            }

            else {
                if (s1[i] == '1') {
                    one_found = true;
                }
                else {
                    zero_found = true;
                    ans += 1;
                }

                if (one_found && zero_found) {
                    ans += 1;
                    one_found = false;
                    zero_found = false;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
