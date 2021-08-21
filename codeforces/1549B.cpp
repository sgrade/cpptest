// B. Gregor and the Pawn Game

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

        string s1, s8;
        cin >> s1 >> s8;

        vector<char> v1(begin(s1), end(s1));

        int ans = 0;

        // Editorial - https://codeforces.com/blog/entry/93586

        for (int i = 0; i < n; ++i) {
            
            if (s8[i] == '1') {
                if (i > 0 && v1[i-1] == '1') {
                    ++ans;
                    v1[i-1] = '0';
                }
                else if (v1[i] == '0') {
                    ++ans;
                }
                else if (i < n-1 && v1[i+1] == '1') {
                    ++ans;
                    v1[i+1] = '0';
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
