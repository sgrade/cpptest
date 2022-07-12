// A. YES or YES?

#include <iostream>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string yes = "yes";

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        for (int i = 0; i < 3; ++i) {
            s[i] = tolower(s[i]);
        }

        cout << (s == yes ? "YES\n" : "NO\n");

    }

    return 0;
}
