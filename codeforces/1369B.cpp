// B. AccurateLee
// Wrong answer on test 2

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

        auto idx_0 = s.rfind('0');
        if (idx_0 != string::npos) {
            cnt1 = n - idx_0 - 1;
        }
        
        auto idx_1 = s.find('1');
        if (idx_1 != string::npos) {
            cnt0 = idx_1;
        }

        if (idx_0 > idx_1) {
            ++cnt0;
        }

        if (cnt1 == 0 && cnt1 == 0) {
            if (s.find('0') != string::npos) {
                cout << '0' << endl;
            }
            else {
                cout << '1' << endl;
            }
        }
        else {
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
