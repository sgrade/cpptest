// C. Dominant Character

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

        int ans = -1;

        // Editorial - https://codeforces.com/blog/entry/96866

        vector<string> ss = {"aa", "aba", "aca", "abca", "acba", "abbacca", "accabba"};
        
        for (auto &subs: ss) {
            if (s.find(subs) != string::npos) {
                ans = size(subs);
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
