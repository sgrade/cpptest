// 1733. Minimum Number of People to Teach
// https://leetcode.com/problems/minimum-number-of-people-to-teach/

#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;
using std::min;


class Solution {
 public:
    int minimumTeachings(int n, const std::vector<std::vector<int>>& languages,
                                             const std::vector<std::vector<int>>& friendships) {
        int users = languages.size();
        std::vector<std::vector<bool>> knows(users, std::vector<bool>(n + 1, false));
        for (int i = 0; i < users; ++i) {
            for (int lang : languages[i]) {
                knows[i][lang] = true;
            }
        }

        std::vector<bool> need_teach(users, false);
        for (const auto& f : friendships) {
            int u1 = f[0] - 1, u2 = f[1] - 1;
            bool can_communicate = false;
            for (int lang = 1; lang <= n; ++lang) {
                if (knows[u1][lang] && knows[u2][lang]) {
                    can_communicate = true;
                    break;
                }
            }
            if (!can_communicate) {
                need_teach[u1] = true;
                need_teach[u2] = true;
            }
        }

        int min_teach = users;
        for (int lang = 1; lang <= n; ++lang) {
            int cur_teach = 0;
            for (int i = 0; i < users; ++i) {
                if (need_teach[i] && !knows[i][lang]) {
                    ++cur_teach;
                }
            }
            if (cur_teach < min_teach) {
                min_teach = cur_teach;
            }
            if (min_teach == 0) {
                break;
            }
        }
        return min_teach;
    }
};
