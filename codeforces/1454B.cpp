// B. Unique Bid Auction

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> v(n);
        map<int, int> mp;
        for (int i=0; i<n; ++i) {
            scanf("%d ", &(v[i]));
            ++mp[v[i]];
        }

        int ans = -1;

        for (auto el: mp){
            if (el.second == 1) {
                ans = distance(v.begin(), find(v.begin(), v.end(), el.first)) + 1;
                break;
            }
        }

        cout << ans << endl;

    }

    return 0;
}
