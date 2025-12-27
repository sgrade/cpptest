// 2483. Minimum Penalty for a Shop
// https://leetcode.com/problems/minimum-penalty-for-a-shop/


class Solution {
public:
    int bestClosingTime(string customers) {
        int cur_penalty = 0, min_penalty = 0, closing_hour = 0;
        for (int i = 0; i < customers.size(); ++i) {
            char c = customers[i];
            if (c == 'Y') {
                cur_penalty--;
            } else {
                cur_penalty++;
            }
            if (cur_penalty < min_penalty) {
                min_penalty = cur_penalty;
                closing_hour = i + 1;
            }
        }
        return closing_hour;
    }
};
