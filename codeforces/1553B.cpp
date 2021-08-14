// B. Reverse String

#include <iostream>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        string s, t;
        cin >> s >> t;

        bool ans = false;

        // Idea from https://codeforces.com/contest/1553/submission/123300909

        for (int i = 0; i < s.size(); ++i) {
            string x = "";
            for (int j = 0; j < i; ++j) {
                x += s[j];
            }
            for (int j = i; j >= 0; --j) {
                x += s[j];
            }
            if (x.find(t) != string::npos) {
                ans = true;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
