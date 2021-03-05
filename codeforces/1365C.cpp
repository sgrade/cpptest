// C. Rotation Matching

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main(){

    int n;
    cin >> n;

    map<int, int> a, b;
    int tmp;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        a[tmp] = i;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        b[tmp] = i;
    }
    
    int ans = 0;

    int shifts;
    map<int, int> mp;
    // Editorial - https://codeforces.com/blog/entry/78504
    for (auto el: a)
    {
        shifts = el.second - b[el.first];
        if (shifts < 0)
            shifts += n;
        
        ++mp[shifts];
    }

    for (auto el: mp)
        ans = max(ans, el.second);
    
    cout << ans << endl;

    return 0;
}
