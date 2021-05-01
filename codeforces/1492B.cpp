// B. Card Deck

#include <iostream>
#include <map>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> p(n);
        map<int, bool, greater<int>> mp;
        for (auto &el: p) {
            cin >> el;
            mp.emplace(pair<int, bool>(el, false));
        }

        vector<int> ans;

        int prev;
        map<int, bool>::iterator it = mp.begin();
        int i = n, j = n;
        while (it != mp.end() && i > -1) {
            prev = it->first;
            while (true) {
                --i;
                mp[p[i]] = true;
                if (p[i] == prev) {
                    break;
                }
            }

            ans.insert(ans.end(), p.begin() + i, p.begin() + j);
            j = i;

            while (it != mp.end() && it->second != false) {
                ++it;
            }
        }

        for (auto &el: ans) {
            cout << el << ' ';
        }
        cout << endl;

    }

    return 0;
}
