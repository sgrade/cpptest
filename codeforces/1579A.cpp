// Casimir's String Solitaire

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        int n = size(s);

        bool ans = true;

        if (n % 2 != 0) {
            ans = false;
        }

        if (ans) {
            int a = 0, b = 0, c = 0;
            for (auto &ch: s) {
                if (ch == 'A') {
                    ++a;
                }
                else if (ch == 'B') {
                    ++b;
                }
                else {
                    ++c;
                }
            }
            
            if (a + c != b) {
                ans = false;
            }
        }

        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
