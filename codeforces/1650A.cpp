// A. Deletions of Two Adjacent Letters

#include <iostream>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        
        string s;
        cin >> s;

        char c;
        cin >> c;

        bool ans = false;

        size_t i = -1;
        while (true) {
            i = s.find(c, i+1);
            if (i == string::npos) {
                break;
            }
            if (i % 2 == 0) {
                ans = true;
                break;
            }
        }

        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
