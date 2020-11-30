// B. Jumps
// Wrong answer

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    vector<int> dp, dp2;
    dp.push_back(0);
    dp2.push_back(-2);
    int cur, prev=dp[0], cur2, prev2=dp2[0];
    int i = 1;
    while(true) {
        cur = prev + i;
        dp.push_back(cur);

        cur2 = prev2 + i;
        dp2.push_back(cur2);

        if (cur > 10e6) break;
        prev = cur;
        prev2 = cur2;

        ++i;
    }
    dp[0] = 0;

    while(t--){

        int n;
        cin >> n;

        auto found = find_if(dp.begin(), dp.end(), [n](int x){
            return x >= n;
        });
        auto found2 = find_if(dp2.begin(), dp2.end(), [n](int x){
            return x >= n;
        }); 

        int index = distance(dp.begin(), found);
        int index2 = distance(dp2.begin(), found2);

        int ans = index + (dp[index] - n);
        int ans1 = index2 + (dp2[index2] - n);

        ans = min(ans, ans1);
        

        cout << ans << endl;

    }

    return 0;
}
