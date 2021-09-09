// A. Domino Disaster

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<char> ans(n);

        for (int i = 0; i < n; ++i) {
            
            if (s[i] == 'U') {
                ans[i] = 'D';
            }
            else if (s[i] == 'D') {
                ans[i] = 'U';
            }

            else {
                ans[i] = 'L';
                ans[i+1] = 'R';
                ++i;
            }
        }

        for (char &ch: ans) {
            cout << ch;
        }
        cout << endl;

    }

    return 0;
}
