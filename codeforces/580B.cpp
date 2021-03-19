// B. Kefa and Company
// Time limit exceeded on test 14

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


int main() {

    int n, d;
    cin >> n >> d;

    multimap<int, int> mp;
    int m, s;
    for (int i = 0; i < n; ++i) {
        cin >> m >> s;
        mp.emplace(pair(m, s));
    }

    unsigned long long ans = 0ULL;

    multimap<int, int>::iterator it1, it2, it3;
    unsigned long long current_ans;
    for (it1 = mp.begin(); it1 != mp.end(); ++it1) {
        current_ans = 0ULL + it1->second;

        it2 = mp.begin();
        while (it2 != mp.end()) {
            if (it1 == it2) {
                ++it2;
                continue;
            }
            if (abs(it2->first - it1->first) < d) {
                current_ans += it2->second;
                break;
            }
            ++it2;
        }

        if (it2 != mp.end()) {
            it3 = it2;
            ++it3;
            while (it3 != mp.end() && abs(it3->first - it2->first) < d && abs(it3->first - it1->first) < d) {
                if (it1 == it3) {
                    ++it3;
                    continue;
                }
                current_ans += it3->second;
                ++it3;
            }

            ++it2;
            while (it2!= mp.end() && it3 != mp.end()) {
                if (abs(it3->first - it1->first) >= d) break;
                if (it1 == it2) {
                    ++it2;
                    continue;
                }
                if (it1 == it3) {
                    ++it3;
                    continue;
                }
                if (it2 == it3) {
                    ++it3;
                    continue;
                }
                if (it3->second > it2->second) {
                    current_ans -= it2->second;
                    current_ans += it3->second;
                }
                ++it2;
                ++it3;
            }
        }
 
        ans = max(ans, current_ans);
    }

    cout << ans << endl;

    return 0;
}
