// 3074. Apple Redistribution into Boxes
// https://leetcode.com/problems/apple-redistribution-into-boxes/

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int apples = 0;
        for (const int pack_size: apple) {
            apples += pack_size;
        }

        sort(capacity.begin(), capacity.end(), greater<int>());
        for (int i = 0; i < capacity.size(); ++i) {
            apples -= capacity[i];
            if (apples <= 0) {
                return i + 1;
            }
        }
        return (int)capacity.size();
    }
};
