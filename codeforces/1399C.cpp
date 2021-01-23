// C. Boats Competition
// Check my Python solution for more efficient implementation

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check(vector<int> v, int s){
    int ans = 0;
    vector<bool> checked(v.size(), false);
    for (int i = 0; i < v.size(); ++i){
        if (checked[i]) continue;
        for (int j = i+1; j < v.size(); ++j){
            if (!checked[j] && v[i] + v[j] == s){
                checked[i] = true;
                checked[j] = true;
                ++ans;
                break;
            }
        }
    }

    return ans;
}


int main(){

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> v(n);
        for (auto &el: v) cin >> el;
        sort(v.begin(), v.end());

        int ans = 0;

        if (n > 1){
            for (int s = v[n-1] + v[n-2]; s >= v[0] + v[1]; --s){
                int tmp = check(v, s);
                ans = max(ans, tmp);
            }
        }
        
        
        cout << ans << endl;

    }

    return 0;
}
