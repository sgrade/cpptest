// B. Make it Divisible by 25

#include <iostream>
#include <string>
#include <limits>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = size(s);

        int ans = numeric_limits<int>::max();

        // Editorial - https://codeforces.com/blog/entry/96034
        for (int i = n-1; i > -1; --i) {
            int cur_ans = n-1 - i;
            if (s[i] == '0') {
                int cur_ans_increment = 0;
                for (int j = i-1; j > -1; --j) {
                    if (s[j] == '5' || s[j] == '0') {
                        if (s[j] == '0' && j == 0) {
                            break;
                        }
                        ans = min(ans, cur_ans + cur_ans_increment);
                        break;
                    }
                    ++cur_ans_increment;
                }
            }

            else if (s[i] == '5') {
                int cur_ans_increment = 0;
                for (int j = i-1; j > -1; --j) {
                    if (s[j] == '2' || s[j] == '7') {
                        ans = min(ans, cur_ans + cur_ans_increment);
                        break;
                    }
                    ++cur_ans_increment;
                }
            }

            ++cur_ans;
        }

        ANS:
        cout << ans << endl;
    }

    return 0;
}
