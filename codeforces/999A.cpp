// A. Mishka and Contest

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (auto &it: v) cin >> it;

    int ans = 0;
    
    ans += distance(v.begin(), find_if(v.begin(), v.end(), [k](int x){
        return x > k;
    }));
    if (ans < n-1){
        ans += distance(v.rbegin(), find_if(v.rbegin(), v.rend(), [k](int x){
            return x > k;
        }));
    }

    cout << ans << endl;

    return 0;
}