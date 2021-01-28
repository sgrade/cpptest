// B. Balls of Steel
 
#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
 
int main(){
 
    int t;
    cin >> t;
 
    while(t--){
 
        int n, k;
        cin >> n >> k;
 
        vector<pair<int, int>> v(n);
        for (auto &pair: v) cin >> pair.first >> pair.second;

        int ans = -1;

        // Editorial - https://codeforces.com/blog/entry/85348
        for (int i = 0; i < n; ++i){
            int mx = 0;

            for (int j = 0; j < n; ++j){
                mx = max(mx, abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second));
            }

            if (mx <= k) {
                ans = 1;
                break;
            }
        }
        
        cout << ans << endl;
 
    }
 
    return 0;
}
