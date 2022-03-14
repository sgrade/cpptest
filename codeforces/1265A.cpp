// A. Beautiful String

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

        string s;
        cin >> s;

        int n = size(s);

        int ans = 0;
        vector<char> output(n+2);
        
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i-1] && s[i] != '?') {
                ans = -1;
            }
        }

        if (ans != -1) {
            vector<char> abc = {'a', 'b', 'c'};

            output[0] = 'd';
            output[n+1] = 'd';

            for (int i = 0; i < n; ++i) {
                if (s[i] != '?') {
                    output[i+1] = s[i];
                    continue;
                }
                for (char &ch: abc) {
                    if (ch != output[i] && ch != s[i+1]) {
                        output[i+1] = ch;
                    }
                }
            }
        }
    
        if (ans == -1) {
            cout << "-1\n";
        }
        else {
            for (int i = 1; i < n+1; ++i) {
                cout << output[i];
            }
            cout << '\n';
        }
    }

    return 0;
}
