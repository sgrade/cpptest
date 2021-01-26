// C. Alternating Subsequence

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> v(n);
        for (auto &el: v) cin >> el;

        long long ans = 0;

        if (n == 1) ans += v[0];
        
        else{
            int prev_index = 0, next_index;
            vector<int>::iterator it;
            while(prev_index != n){
                if (v[prev_index] > 0){
                    it = find_if(v.begin() + prev_index, v.end(), [](int x){return x < 0;});
                }
                else {
                    it = find_if(v.begin() + prev_index, v.end(), [](int x){return x > 0;});
                }
                next_index = distance(v.begin(), it);

                ans += *max_element(v.begin() + prev_index, v.begin() + next_index);
                prev_index = next_index;
            }
        }
                
        cout << ans << endl;

    }

    return 0;
}
