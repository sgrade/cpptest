// A. Kitchen Utensils

#include <iostream>
#include <map>

using namespace std;


int main() {

    int n, k;
    cin >> n >> k;

    // Editorial - https://codeforces.com/blog/entry/63324

    int tmp;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        ++mp[tmp];
    }

    int mx = 0;
    for (auto &p: mp) {
        mx = max(mx, p.second);
    }

    int t = size(mp);
    
    int p = (mx + k - 1) / k;

    int ans = p * t * k - n;

    cout << ans << endl;
    
    return 0;
}
