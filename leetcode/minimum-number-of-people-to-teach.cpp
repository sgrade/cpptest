// 1733. Minimum Number of People to Teach
// https://leetcode.com/problems/minimum-number-of-people-to-teach/

#include <vector>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::unordered_set;
using std::set_intersection;
using std::back_inserter;
using std::max;


// Based on Editorial's Approach: Greedy
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int users = languages.size();
        for (vector<int>& user: languages) {
            sort(user.begin(), user.end());
        }

        // Can communicate already
        unordered_set<int> cannot_communicate;
        for (const vector<int>& f: friendships) {
            int user1 = f[0] - 1, user2 = f[1] - 1;
            const vector<int>& l1 = languages[user1], l2 = languages[user2];
            vector<int> v_intersection; 
            set_intersection(l1.begin(), l1.end(), l2.begin(), l2.end(), back_inserter(v_intersection));
            if (v_intersection.size() == 0) {
                cannot_communicate.emplace(user2);
                cannot_communicate.emplace(user1);
            }
        }

        int max_friends_know_language = 0;
        vector<int> friends_know(n + 1);
        for (const int user: cannot_communicate) {
            for (const int language: languages[user]) {
                ++friends_know[language];
                max_friends_know_language = max(friends_know[language], max_friends_know_language);
            }
        }
        int ans = cannot_communicate.size() - max_friends_know_language;
        return ans;
    }
};
