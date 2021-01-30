// B. Inflation
// NOT FINISHED

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;

        vector<ll> p(n);
        for (auto &el: p) cin >> el;

        vector<ll> v(n);
        v[0] = p[0];
        for (int i = 1; i < n; ++i) {
            v[i] = v[i-1] + p[i];
        }
        
        ll sm = 0;
        ll tmp;
        for (int i = n-1; i > 0; --i){
            ll koef = (p[i] * 100 + k - 1) / k;
            tmp = max(koef - v[i-1], 0LL);
            if (tmp > 0){
                sm += tmp;
                // cout << tmp << endl;
                break;
            }
        }

        cout << sm << endl;

    }

    return 0;
}
