// B. Toy Blocks

#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
using ull = unsigned long long;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        ull a[n];
        for (auto &el: a) cin >> el;
        
        ull ans = 0;
        
        // Editorial - https://codeforces.com/blog/entry/84847
        ull sum = accumulate(a, a+n, (ull)0);
        ull max_el = *max_element(a, a+n);
        ull k = max(max_el, (sum + (n-1) - 1) / (n-1));
        ans = k * (n-1) - sum;
        
        cout << ans << endl;

    }

    return 0;
}
