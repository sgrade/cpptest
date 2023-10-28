// C. Qingshan Loves Strings 2
// NOT FINISHED

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
        string s;
        cin >> s;

        bool ans = true;
        vector<int> output;

        if (n % 2 != 0) {
            ans = false;
            goto ANS;
        }

        // The string is already good
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] == s[n - i - 1]) {
                ans = false;
                break;
            }
        }
        if (ans)
            goto ANS;


        ANS:
            if (!ans)
                cout << "-1\n";
            else {
                cout << output.size() << "\n";
                for (const int& el: output)
                    cout << el << ' ';
                cout << "\n";
            }
    }

    return 0;
}
