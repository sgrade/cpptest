// D. Not a Cheap String

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        string w;
        cin >> w;

        int n = w.size();
                
        int p;
        cin >> p;

        int sm = 0;

        unordered_map<int, queue<int>> counter;
        
        int x;
        for (int i = 0; i < n; ++i) {
            x = w[i] - 'a' + 1;
            counter[x].emplace(i);
            sm += x;
        }
        
        int idx = 27;
        while (sm > p) {
            while (idx > 0 && (counter.find(idx) == counter.end() || counter[idx].empty())) {
                --idx;
            }
            if (idx == 0) break;
            x = counter[idx].front();
            sm -= idx;
            counter[idx].pop();
        }

        string ans = "";

        for (int i = 0; i < n; ++i) {
            x = w[i] - 'a' + 1;
            if (counter[x].empty() || counter[x].front() != i) {
                continue;
            }
            counter[x].pop();
            ans += w[i];
        }

        cout << ans << '\n';
    }

    return 0;
}
