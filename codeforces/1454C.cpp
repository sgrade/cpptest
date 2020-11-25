// C. Sequence Transformation

#include <iostream>
#include <algorithm>
#include <map>
#include <limits>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int ans = 0;

        int prev;
        cin >> prev;

        if (n > 1){
            map<int, int> mp;
            int cur;
            for (int i=1; i<n; ++i){
                cin >> cur;
                if (cur != prev){
                    ++mp[prev];
                    if (mp.find(cur) == mp.end()) ++mp[cur];
                    prev = cur;
                }
            }

            if (!mp.empty()){
                int m = numeric_limits<int>::max();
                for (auto el: mp){
                    if (el.second < m) m = el.second;
                }
                ans = m;
            }
        }

        cout << ans << endl;

    }

    return 0;
}
