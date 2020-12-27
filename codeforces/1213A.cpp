// A. Chips Moving

#include <iostream>
#include <map>
#include <limits>
#include <algorithm>

using namespace std;
using ull = unsigned long long;


int main(){

    int n;
    cin >> n;

    map<ull, ull> mp;
    int tmp;
    for (int i = 0; i < n; ++i){
        cin >> tmp;
        ++mp[tmp];
    }

    ull ans = numeric_limits<ull>::max();

    for (auto el: mp){
        ull currentCoins = 0;
        for (auto elem: mp){
            if (el.first != elem.first && llabs(el.first - elem.first) % 2 != 0) {
                currentCoins += elem.second;
            }
        }
        if (currentCoins < ans) ans = currentCoins;
    }

    cout << ans << endl;

    return 0;
}
