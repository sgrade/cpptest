// C. Basic Diplomacy
// NOT FINISHED

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        int half_m = (m + 1) / 2;

        vector<set<int>> days(m);
        vector<int> cnt(n, 0);
        vector<vector<int>> days_per_friend(n);
        
        int k, tmp;
        for (int i = 0; i < m; ++i) {
            cin >> k;
            for (int j = 0; j < k; ++j) {
                cin >> tmp;
                --tmp;
                ++cnt[tmp];
                days[i].insert(tmp);
                days_per_friend[tmp].push_back(i);
            }
        }
        
        for (int i = 0; i < m; ++i) {
            cnt[i] = min(cnt[i], half_m);
        }

        bool ans = true;
        
        vector<int> output(m, -1);
        for (int i = 0; i < m; ++i) {
            for (auto f: days[i]) {
                if (cnt[f] > 0) {
                    --cnt[f];
                    output[i] = f;
                    break;
                }
            }
        }

        int idx_d = 0, idx_f = 0;
        vector<int>::iterator it_d = find(output.begin(), output.end(), -1);
        while (it_d != output.end())
        {
            idx_d = distance(output.begin() + idx_d, it_d);

            vector<int>::iterator it_f = find_if(cnt.begin(), cnt.end(), [](int x){
                return x > 0;
            });
            if (it_f != cnt.end()) {
                idx_f = distance(cnt.begin(), it_f);
                // Looking for days, where idx_f is present and one of the zeroes sits
                for (auto day: days_per_friend[idx_f]) {
                    // STOPPED HERE
                }
            }
            else {
                ans = false;
                break;
            }
        }
        
        cout << (ans ? "YES" : "NO") << endl;
        if (ans) {
            for (auto &el: output) {
                cout << el << ' ';
            }
            cout << endl;
        }

    }

    return 0;
}
