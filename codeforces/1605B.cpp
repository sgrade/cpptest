// B. Reverse Sort

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int ans = 0;
        vector<int> output;

        bool issorted = is_sorted(begin(s), end(s));
        
        if (!issorted) {
            
            // Editorial - https://codeforces.com/blog/entry/96866

            ans = 1;

            int zeroes = count(begin(s), end(s), '0');
            int ones = n - zeroes;

            for (int i = 0; i < n; ++i) {
                if (i < zeroes) {
                    if (s[i] == '1') {
                        output.push_back(i + 1);
                    }
                }

                else {
                    if (s[i] == '0') {
                        output.push_back(i + 1);
                    }
                }
            }
        }

        cout << ans << endl;
        if (ans == 1) {
            cout << size(output) << ' ';
            for (auto &el: output) {
                cout << el << ' ';
            }
            cout << endl;
        }

    }

    return 0;
}
