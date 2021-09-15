// B. AccurateLee

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        cin >> s;

        int cnt0 = 0, cnt1 = 0;

        // Editorial - https://codeforces.com/blog/entry/79235
        
        bool string_is_non_decreasing = true;
        for (int i = 0; i < n-1; ++i) {
            if (s[i] > s[i+1]) {
                string_is_non_decreasing = false;
                break;
            }
        }

        if (string_is_non_decreasing) {
            cout << s << endl;
        }

        else {
            auto idx_0 = s.rfind('0');
            if (idx_0 != string::npos) {
                cnt1 = n - idx_0 - 1;
            }
            
            auto idx_1 = s.find('1');
            if (idx_1 != string::npos) {
                cnt0 = idx_1 + 1;
            }

            for (int i = 0; i < cnt0; ++i) {
                cout << '0';
            }
            for (int i = 0; i < cnt1; ++i) {
                cout << '1';
            }
            cout << endl;

        }       
    }

    return 0;
}
