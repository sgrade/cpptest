// C. Berland Regional
// Time limit exceeded on test 4
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
 
using namespace std;
using ull = unsigned long long;
 
int main() {
 
    int t;
    cin >> t;
 
    while (t--) {
 
        int n;
        cin >> n;
 
        vector<int> u(n);
        for (auto &el: u) {
            cin >> el;
        }
 
        map<int, multiset<int>> mp;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            mp[u[i]].insert(tmp);
        }
 
        size_t mx = 0;
        map<int, ull> u_s;
        for (auto &el: mp) {
            mx = max(mx, el.second.size());
            u_s[el.first] = accumulate(el.second.begin(), el.second.end(), 0ULL);
        }
 
        unsigned long long s;
        multiset<int>::iterator it;
        for (int k = 1; k < mx + 1; ++k) {
            s = 0ULL;
            for (auto &el: mp) {
                s += u_s[el.first];
                it = el.second.begin();
                int rem = el.second.size() % k;
                while (rem--) {
                    s -= *it;
                    ++it;
                }
            }
            cout << s << ' ';
        }
 
        for (int k = mx + 1; k < n + 1; ++k) {
            cout << 0 << ' ';
        }
        cout << endl;
 
    }
 
    return 0;
}
