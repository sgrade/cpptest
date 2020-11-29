// 

#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){

    int t;
    cin >> t;

    while(t--){

        ll n, m, r, c;
        cin >> n >> m >> r >> c;

        ll ans = max({abs(1-r) + abs(1-c), abs(n-r) + abs(m-c), abs(1-r) + abs(m-c), abs(n-r) + abs(1-c)});

        /*
        for (ll i = 1; i <= n; ++i){
            for (ll j = 1; j <= m; ++j){
                if (i == r && j == c) continue;
                else {
                    int tmp = abs(i - r) + abs(j - c);
                    if (tmp > ans) ans = tmp;
                }
            }
        }
        */

        cout << ans << endl;

    }

    return 0;
}
