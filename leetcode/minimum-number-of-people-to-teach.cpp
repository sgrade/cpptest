// 1733. Minimum Number of People to Teach
// https://leetcode.com/problems/minimum-number-of-people-to-teach/

#include <vector>
#include <unordered_set>
#include <climits>

using std::vector;
using std::unordered_set;
using std::min;


class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int users = languages.size();
        // Convert each user's language list to unordered_set for O(1) lookup
        vector<unordered_set<int>> user_lang(users);
        for (int i = 0; i < users; ++i) {
            for (int lang : languages[i]) {
                user_lang[i].insert(lang);
            }
        }

        // Find users who cannot communicate in any friendship
        unordered_set<int> need_teach;
        for (const auto& f : friendships) {
            int u1 = f[0] - 1, u2 = f[1] - 1;
            bool can_communicate = false;
            for (int lang : user_lang[u1]) {
                if (user_lang[u2].count(lang)) {
                    can_communicate = true;
                    break;
                }
            }
            if (!can_communicate) {
                need_teach.insert(u1);
                need_teach.insert(u2);
            }
        }

        // For each language, count how many need_teach users do not know it
        int min_teach = INT_MAX;
        for (int lang = 1; lang <= n; ++lang) {
            int cur_teach = 0;
            for (int user : need_teach) {
                if (!user_lang[user].count(lang)) {
                    ++cur_teach;
                }
            }
            min_teach = min(min_teach, cur_teach);
            if (min_teach == 0) {
                break; // Early exit
            }
        }
        return min_teach == INT_MAX ? 0 : min_teach;
    }
};
