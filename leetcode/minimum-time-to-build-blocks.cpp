// 1199. Minimum Time to Build Blocks
// https://leetcode.com/problems/minimum-time-to-build-blocks/

#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

// Based on Editorial's Approach 1: Top-down Dynamic Programming
class Solution {
 public:
  int minBuildTime(vector<int>& blocks, int split) {
    sort(blocks.begin(), blocks.end(), greater<int>());
    memo.assign(blocks.size(), vector<int>(blocks.size() + 1, -1));
    return minTime(blocks, split, /*blockIndex=*/0, /*workers=*/1);
  }

 private:
  // memo[i][w] = min time to build blocks[i..] with w workers
  vector<vector<int>> memo;

  int minTime(vector<int>& blocks, int split, int blockIndex, int workers) {
    int n = blocks.size();
    if (blockIndex == n) {
      return 0;
    }
    if (workers == 0) {
      return INT_MAX;
    }
    int remaining = n - blockIndex;
    if (workers >= remaining) {
      return blocks[blockIndex];
    }
    if (memo[blockIndex][workers] != -1) {
      return memo[blockIndex][workers];
    }

    // Use one worker to build the current (largest remaining) block.
    int buildTime = max(blocks[blockIndex],
                        minTime(blocks, split, blockIndex + 1, workers - 1));
    // Split every worker, doubling the worker count.
    int splitTime =
        split + minTime(blocks, split, blockIndex, min(2 * workers, remaining));

    return memo[blockIndex][workers] = min(buildTime, splitTime);
  }
};
