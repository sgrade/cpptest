// C. Unstable String

#include <iostream>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        string s;
        getline(cin >> ws, s);

        unsigned long long ans = 0ULL;

        int n = size(s);

        int cnt = 1;
        int i = 0;
        while (i < n) {
            
            while (s[i] == '?' && i < n) {
                ans += cnt;
                ++i;
                ++cnt;
            }

            int consequitive_q_marks = 0;
            int j = i;
            for (; j < n; ++j) {

                if (s[j] != '?') {
                    
                    // different parity
                    if ((i ^ j) & 1) {
                        if (s[i] == s[j]) {
                            break;
                        }
                    }
                    // same parity
                    else {
                        if (s[i] != s[j]) {
                            break;
                        }
                    }

                    consequitive_q_marks = 0;
                }

                else {
                    ++consequitive_q_marks;
                }

                ans += cnt;
                ++cnt;
            }

            i = j;
            cnt = 1;
            if (i > 0 && s[i-1] == '?') {
                cnt += consequitive_q_marks;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
