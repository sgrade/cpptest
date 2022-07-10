// B. Polycarp Writes a String from Memory

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        int ans = 0;

        unordered_set<char> counter;
        
        int x = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (counter.find(s[i]) != counter.end()) {
                continue;
            }
            if (!counter.empty() && counter.size() % 3 == 0) {
                counter.clear();
                ++ans;
            }
            counter.emplace(s[i]);
        }

        if (!counter.empty()) ++ans;

        cout << ans << '\n';
    }

    return 0;
}
