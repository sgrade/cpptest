// D1. Seating Arrangements (easy version)

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <numeric>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> a(m);
        map<int, int> cnt;
        for (int i = 0; i < m; ++i) {
            cin >> a[i].first;
            ++cnt[a[i].first];
        }

        // Shifting counts to a number of seats for people with poorer eyesight
        auto it1 = begin(cnt), it2 = begin(cnt);
        ++it2; 
        while (it2 != end(cnt)) {
            it2->second += it1->second;
            ++it1;
            ++it2;
        }

        int ans = 0;
        
        vector<int> occupied(m+m+2);
        int idx;
        int current_inconvenience;
        for (int i = 0; i < m; ++i) {
            idx = a[i].second + cnt[a[i].first];
            current_inconvenience = accumulate(begin(occupied), begin(occupied) + idx, 0);
            ans += current_inconvenience;
            occupied[idx-1] = 1;
            --cnt[a[i].first];
        }

        cout << ans << '\n';
    }

    return 0;
}
