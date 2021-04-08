// B. Box Fitting

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main() {

    int t;
    cin >> t;

    map<int, int, greater <int>> mp;
    int W;

    while (t--) {

        int n;
        cin >> n >> W;

        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            ++mp[tmp];
        }

        int ans = 1;

        map<int, int>::iterator it_mp = mp.begin();
        int w_left = W, i = 0;
        while (i < n) {
            it_mp = find_if(mp.begin(), mp.end(), [w_left](pair<int, int> p){
                return p.first <= w_left && p.second > 0;
            });
            if (it_mp == mp.end()) {
                ++ans;
                w_left = W;
            }
            else {
                --it_mp->second;
                w_left -= it_mp->first;
                ++i;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
