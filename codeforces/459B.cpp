// B. Pashmak and Flowers

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main() {

    int n;
    cin >> n;

    int tmp;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        ++mp[tmp];
    }

    int max_diff = 0;
    long long num_of_ways = 1LL * mp.begin()->second * (mp.begin()->second - 1) / 2;
    
    if (mp.size() > 1) {
        max_diff = mp.rbegin()->first - mp.begin()->first;
        num_of_ways = 1LL * mp.begin()->second * mp.rbegin()->second;
    }

    cout << max_diff << ' ' << num_of_ways << endl;

    return 0;
}
