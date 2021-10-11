// A. Computer Game

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

        bool ans = true;

        for (int i = 0; i < n-1; ++i) {
            if (s1[i] == '1' && s2[i] == '1') {
                ans = false;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}
