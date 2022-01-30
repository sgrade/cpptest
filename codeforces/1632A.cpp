// A. ABC

#include <iostream>
#include <string>
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

        bool ans = false;
        
        if (n == 1) {
            ans = true;
        }

        else if (n == 2) {
            if (s == "10" || s == "01") {
                ans = true;
            }
        }
        
        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}
