// B. Balanced Remainders

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


int main() {
    
    int t;
    cin >> t;

    while (t--) {
        int n; 
        cin >> n;

        int tmp;
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            ++mp[tmp%3];
        }

        int ans = 0;

        // Idea - https://codeforces.com/contest/1490/submission/108133578
        ans = max(ans, mp[0] - mp[2]);
        ans = max(ans, mp[1] - mp[0]);
        ans = max(ans, mp[2] - mp[1]);

        cout << ans << endl;
    }

    return 0;
}
