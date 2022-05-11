// F. Longest Strike

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

            map<int, int>::iterator it1 = mp.begin(), it2;
            ans = 0;
            l = it1->first;
            r = it1->first;

            while (it1 != mp.end()) {

                cur_l = it1->first;
                it2 = it1;
                ++it2;

                while (it2 != mp.end()) {

                    if (it2->first - it1->first > 1){
                        break;
                    }

                    cur_r = it2->first;
                    cur_ans = cur_r - cur_l;
                    if (cur_ans > ans) {
                        ans = cur_ans;
                        r = cur_r;
                        l = cur_l;
                    }

                    ++it1;
                    ++it2;
                }

                it1 = it2;
            }

        }

        if (ans == -1) cout << "-1\n";
        else {
            cout << l << ' ' << r << '\n';
        }
    }

    return 0;
}
