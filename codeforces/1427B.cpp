// B. Chess Cheater

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        getline(cin >> ws, s);

        int ans;
        // Processing input
        ans = s[0] == 'W' ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == 'W') {
                if (s[i-1] == 'W') {
                    ans += 2;
                }
                else {
                    ans += 1;
                }
            }
        }

        // Processing intervals with 'L' after 'W'
        auto first_l_after_w = find(begin(s), end(s), 'W');
        first_l_after_w = find(first_l_after_w, end(s), 'L');
        if (first_l_after_w != end(s)) {

            multimap<int, int> intervals;

            while (first_l_after_w != end(s)) {
                int cur_int_begin = distance(begin(s), first_l_after_w);

                auto first_w_after_l = find(first_l_after_w, end(s), 'W');
                if (first_w_after_l == end(s)) {
                    break;
                }
                else {
                    int cur_int_len = distance(first_l_after_w, first_w_after_l);
                    intervals.insert(pair<int, int>(cur_int_len, cur_int_begin));
                    first_l_after_w = find(first_w_after_l, end(s), 'L');
                }
            }

            if (!intervals.empty()) {
                auto it = begin(intervals);
                while(k > 0 && it != end(intervals)) {
                    int cur_int_len = it->first;
                    ans += 2 * min(k, cur_int_len);
                    // Interval end (next 'W' should change to 2 instead o f 1)
                    if (cur_int_len <= k) {
                        ++ans; 
                    }
                    k -= cur_int_len;
                    ++it;
                }
            }
        }

        if (k > 0) {
            // Suffix of 'L' after 'W'
            auto last_w_idx = s.find_last_of('W');
            if (last_w_idx != string::npos) {
                int suffix_of_l_len = n - (last_w_idx + 1);
                ans += min(k, suffix_of_l_len) * 2;
                k -= suffix_of_l_len;
            }
            
            if (k > 0) {
                auto first_w_idx = s.find_first_of('W');
                int prefix_of_l_len;
                if (first_w_idx == string::npos) {
                    prefix_of_l_len = n;
                }
                else {
                    prefix_of_l_len = first_w_idx;
                    // First 'W' after the prefix switch from 1 to 2
                    ++ans;
                }
                ans += min(k, prefix_of_l_len) * 2;
                // First 'W' gives 1 point
                --ans;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
