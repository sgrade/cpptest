// B. Prefix Removals

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

        int i;
        for (i = 0; i < size(s) - 1; ++i) {
            if (s.find(s[i], i+1) == string::npos ) {
                break;
            }
        }

        for (; i < size(s); ++i) {
            cout << s[i];
        }
        cout << '\n';
    }

    return 0;
}
