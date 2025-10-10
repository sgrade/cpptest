// 3147. Taking Maximum Energy From the Mystic Dungeon
// https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/

#include <vector>
#include <climits>

using std::vector;
using std::max;


// Based on Editorial's Taking Maximum Energy From the Mystic Dungeon
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = INT_MIN;
        int n = energy.size();
        for (int i = n - k; i < n; ++i) {
            int cur_ans = 0;
            for (int j = i; j >= 0; j -= k) {
                cur_ans += energy[j];
                ans = max(ans, cur_ans);
            }
        }
        return ans;
    }
};
