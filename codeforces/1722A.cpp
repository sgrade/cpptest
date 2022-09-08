// A. Spell Check

#include <iostream>
#include <string>
#include <vector>

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

        bool ans = (s.size() == 5 ? true : false);

        if (ans) {
            vector<char> v = {'T', 'i', 'm', 'u', 'r'};
            for (const char &c: v) {
                if (s.find(c) == string::npos) {
                    ans = false;
                    break;
                }
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
