// 

#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
using ull = unsigned long long ;


int main(){

    int t;
    cin >> t;

    while(t--){

        ull n, x;
        cin >> n >> x;

        ull a[n];
        for (auto &el: a) cin >> el;

        ull mn = (accumulate(a, a+n, 0ULL) + x - 1) / x;

        ull mx = 0ULL;
        for (auto el: a){
            mx += (el + x - 1) / x;
        }

        cout << mn << ' ' << mx << endl;

    }

    return 0;
}
