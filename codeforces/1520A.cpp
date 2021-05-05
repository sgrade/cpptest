// A. Do Not Be Distracted!

#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        getline(cin >> ws, s);

        set<char> started;

        bool ans = true;

        if (n > 1) {
            char prev = s[0];
            started.insert(s[0]);
            for (int i = 1; i < n; ++i) {
                if (s[i] != prev) {
                    if (started.find(s[i]) != started.end()) {
                        ans = false;
                        break;
                    }
                    started.insert(s[i]);
                }
                prev = s[i];
            }
        }

        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}
