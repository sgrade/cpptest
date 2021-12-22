// A. Square String?

#include <iostream>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = size(s);

        bool ans = false;

        if (s.substr(0, n/2) == s.substr(n/2, n)) {
            ans = true;
        }

        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
