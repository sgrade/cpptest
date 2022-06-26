// 350. Intersection of Two Arrays II
// https://leetcode.com/problems/intersection-of-two-arrays-ii/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }
        unordered_map<int, int> counter;
        for (const int &num: nums1) {
            ++counter[num];
        }
        
        /*  From leetcode:
            For our solutions here, we use one of the arrays to store the result. 
            As we find common numbers, we copy them to the first array starting from the beginning. 
            This idea is from this solution by sankitgupta.
        */
        int k = 0;
        unordered_map<int, int>::iterator it;
        for (const int &num: nums2) {
            it = counter.find(num);
            if (it != counter.end() && --it->second >= 0) {
                nums1[k++] = num;
            }
        }
        return vector(nums1.begin(), nums1.begin() + k);
    }
};
