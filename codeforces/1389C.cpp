// C. Good String

#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <limits>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        string s;
        getline(cin >> ws, s);

        int ans = numeric_limits<int>::max();

        int n = s.size();

        // Editorial - https://codeforces.com/blog/entry/80809

        map<char, int> cnt;
        for (const auto &ch: s) {
            ++cnt[ch];
        }
    
        // Generate all possible combinations
        map<vector<char>, int> combinations;
        auto it1 = begin(cnt), it2 = begin(cnt);
        while (it1 != end(cnt)) {
            it2 = begin(cnt);
            while (it2 != end(cnt)) {
                vector<char> current_combination {it1->first, it2->first};
                combinations[current_combination] = 0;
                ++it2;
            }
            ++it1;
        }

        // Check how many combinations can be created from s
        for (auto &combination: combinations) {
            char ch1 = combination.first[0], ch2 = combination.first[1];
            int ch_cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == ch1) {
                    ++ch_cnt;
                    swap(ch1, ch2);
                }
            }
            
            // If target string size is odd, all elements should be equal
            // If it is even, all odd elements should be equal and all even elements should be equal
            // so there should be only two chars left: odd and even
            if (ch_cnt % 2 != 0) {
                if (ch1 != ch2) {
                    --ch_cnt;
                }
            }
            
            combination.second = ch_cnt;
        }

        for (const auto &combination: combinations) {
            ans = min(ans, n - combination.second);
        }

        cout << ans << endl;
    }

    return 0;
}
