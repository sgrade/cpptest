// B. Find the Spruce

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        vector<vector<int>> v(n);
        vector<int> tmpV(m);
        char tmp;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j) {
                cin >> tmp;
                tmpV[j] = 1 ? tmp == '*' : 0;
            }
            v[i] = tmpV;
        }

        long long ans = 0LL;

        vector<int> dpTmp(m,0);
        vector<vector<int>> dp(n, dpTmp);

        for (int i = n-1; i >= 0; --i){
            for (int j = 0; j < m; ++j){
                if (v[i][j] == 1){
                    dp[i][j] = 1;
                    if (i+1 < n && j-1 >= 0 && j+1 <m){
                        dp[i][j] += min({dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]});
                    }
                    ans += dp[i][j];
                }
            }
        }

        cout << ans << endl;

    }

    return 0;
}
