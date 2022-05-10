// F. Longest Strike
// NOT FINISHED

#include <iostream>
#include <vector>
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
        }

        bool ans = false;
        int d = 0;

        if (mp.size() > 0) {

            int l, r;

            it = mp.begin();

            map<int, int>::reverse_iterator rit = mp.rbegin();

            while (true) {
                
                if (it == mp.end() || rit == mp.rend()) break;

                l = it -> first;
                r = rit ->first;
                
                if (l > r) break;

                for (int i = l; l <= r; ++l) {
                    if (mp.find(i) == mp.end()) break;
                }
            }

        }
    }

    return 0;
}
