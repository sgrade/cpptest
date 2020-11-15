// B. Numbers Box
// NOT FINISHED

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        vector<vector<int>> v(n);
        for (int i = 0; i<n; ++i){
            vector<int> tmp(m);
            for (auto &el: tmp) cin >> el;
            v[i] = tmp;
        }

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (v[i][j] >= 0) continue;
                else{
                    multimap<int, pair<int, int>> mp;
                    // up
                    if(i != 0) mp.insert(pair<int, pair<int, int>>(v[i-1][j], pair<int, int>(i - 1, j)));
                    // down
                    if(i != n - 1) mp.insert(pair<int, pair<int, int>>(v[i+1][j], pair<int, int>(i + 1, j)));
                    // left
                    if (j != 0) mp.insert(pair<int, pair<int, int>>(v[i][j-1], pair<int, int>(i, j - 1)));
                    // right
                    if (j != m - 1) mp.insert(pair<int, pair<int, int>>(v[i][j+1], pair<int, int>(i, j + 1)));
                    
                    int canidate = mp.begin()->first;
                    if (canidate <= 0  || canidate < abs(v[i][j])){
                        v[i][j] *= -1;
                        v[(mp.begin()->second).first][(mp.begin()->second).second] *= -1;
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i){
            ans += accumulate(v[i].begin(), v[i].end(), 0);
        }

        cout << ans << endl;

    }

    return 0;
}
