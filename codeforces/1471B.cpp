// B. Strange List

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
using ull = unsigned long long;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (auto &el: a) {
            cin >> el;
        }

        ull ans = accumulate(a.begin(), a.end(), 0ULL);

        bool stop = false;
        pair<int, int> tmp;

        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i){
            if (a[i] % x == 0) {
                tmp = make_pair(a[i]/x, x);
                v.push_back(tmp);
            }
            else {
                stop = true;
                break;
            }
        }

        ull i = 0;
        while(!stop){
            if (v[i].first % x == 0){
                tmp = make_pair(v[i].first / x, v[i].second * x);
                v.push_back(tmp);
                ++i;
            }
            else {
                stop = true;
                break;
            }
        }

        for (auto el: v){
            ans += (ull)(el.first * el.second);
        }

        cout << ans << endl;

    }

    return 0;
}
