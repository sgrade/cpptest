// B. A Perfectly Balanced String?

#include <iostream>
#include <map>
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

        int n = s.size();

        bool ans = true;

        map<char, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
           mp[s[i]].push_back(i);
        }

        int dist = mp.size();
        for (auto &p: mp) {
            for (int i = 1; i < p.second.size(); ++i) {
                if (p.second[i] - p.second[i-1] != dist) {
                    ans = false;
                    goto ANS;
                }
            }
        }

        ANS:
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}
