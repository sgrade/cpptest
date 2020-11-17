// B. Sum of Medians

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

int main(){

    int t;
    cin >> t;

    while(t--){

        ull n, k;
        cin >> n >> k;

        vector<ull> v(n*k);
        for (auto &el: v) cin >> el;

        reverse(v.begin(), v.end());

        int step = n / 2;

        ull ans = 0;

        int count = k;
        for (int i = step; k > 0; i += step + 1){
            ans += v[i];
            --k;
        }
        cout << ans << endl;

    }

    return 0;
}
