// A. AB Balance

#include <iostream>
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

        int ab = 0, ba = 0;

        for (int i = 0; i < n-1; ++i) {
            if (s[i] == 'a') {
                if (s[i+1] == 'b'){
                    ++ab;
                }
            }
            else {
                if (s[i+1] == 'a') {
                    ++ba;
                }
            }
        }

        int ans = abs(ab - ba);
        vector<char> output (begin(s), end(s));
        if (ans > 0) {
            if (s[0] == 'a') {
                output[0] = 'b';
            }
            else {
                output[0] = 'a';
            }
        }

        for (auto &ch: output) {
            cout << ch;
        }
        cout << endl;
    }

    return 0;
}
