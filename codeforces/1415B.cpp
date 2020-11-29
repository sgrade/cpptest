// B. Repainting Street

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <limits>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        map<int, int> mp;

        for (auto &el: a) {
            cin >> el;
            ++mp[el];
        }

        int ans = numeric_limits<int>::max();

        if (mp.size() == a.size()){
            ans = n - 1;
        }
        else {
            int mxCount = 0;
            for (auto el: mp) {
                if (el.second > mxCount) mxCount = el.second;
            }
            
            vector<int> allMx;
            for (auto el: mp){
                if (el.second == mxCount) {
                    allMx.push_back(el.first);
                }
            }

            for (int j=0; j<allMx.size(); ++j){
                int nextMx = allMx[j];
                int curAns = 0;
                int i = 0;
                while (true){
                    if (i > n-1) break;
                    auto found = find_if_not(a.begin()+i, a.end(), [nextMx](int x){return x==nextMx;});
                    if (found != a.end()){
                        ++curAns;
                        i += distance(a.begin()+i, found);
                    }
                    i += k;
                }
                if (curAns < ans) ans = curAns;
            }
        }

        cout << ans << endl;

    }

    return 0;
}
