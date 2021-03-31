// A. Reconnaissance

#include <iostream>
#include <map>

using namespace std;


int main() {

    int n, d;
    cin >> n >> d;

    map<int, int> mp;
    int tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        ++mp[tmp];
    }

    unsigned long long ans = 0ULL;

    if (n == 1) {
        ans = 1;
    }
    else {
        map<int, int>::iterator it1 = mp.begin(), it2;
        while (it1 != mp.end()) {
            ans += it1->second * (it1->second - 1);

            it2 = mp.begin();
            while(it2 != mp.end()) {
                if (it1 == it2) {
                    ++it2;
                    continue;
                }
                if (abs(it1->first - it2->first) <= d) {
                    ans += it1->second * it2->second;
                }
                ++it2;
            }
            ++it1;
        }
    }

    cout << ans << endl;
    
    return 0;
}
