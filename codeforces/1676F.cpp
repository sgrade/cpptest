// F. Longest Strike
// Time limit exceeded on test 6

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        map<int, int> mp;

        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            ++mp[tmp];
        }

        map<int, int>::iterator it = mp.begin();

        while (it != mp.end()) {
            if (it->second < k) mp.erase(it++);
            else ++it;
        }

        int ans = -1, cur_ans;
        int l, r, cur_l, cur_r;

        if (mp.size() > 0) {

            it = mp.begin();

            map<int, int>::reverse_iterator rit;

            while (it != mp.end()) {

                rit =  mp.rbegin();

                while (rit != mp.rend()) {

                    cur_l = it -> first;
                    cur_r = rit ->first;
                    
                    if (cur_l > cur_r) break;

                    bool found = true;
                    for (int i = cur_l; i <= cur_r; ++i) {
                        if (mp.find(i) == mp.end()) {
                            found = false;
                            break;
                        }
                    }

                    if (found) {
                        cur_ans = cur_r - cur_l;
                        if (cur_ans > ans) {
                            ans = cur_ans;
                            l = cur_l;
                            r = cur_r;
                        }
                    }
                    ++rit;
                }

                ++it;
            }

        }

        if (ans == -1) cout << "-1\n";
        else {
            cout << l << ' ' << r << '\n';
        }
    }

    return 0;
}
