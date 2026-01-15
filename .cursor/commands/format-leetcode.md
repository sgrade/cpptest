# format-leetcode

Review the code and apply the Google C++ Style Guide with the following exceptions:
- Use `using namespace std;` instead of `std::` prefixes.
- Do NOT change the name and the signature of the classes and functions given in the LeetCode problem statement.


## Standard Problem Annotation

Ensure the file starts with exactly this format:
```cpp
// [number]. [Problem Title]
// https://leetcode.com/problems/[problem-slug]/

#include <vector>

using namespace std;

// [Optional comment about approach or time/space complexity]
class Solution {
 public:
  int solutionFunction() {
    return 0;
  }
};
```

Example:
```cpp
// 3453. Separate Squares I
// https://leetcode.com/problems/separate-squares-i/

#include <algorithm>
#include <vector>

using namespace std;

// Binary search to find the horizontal line that divides total area in half.
// Time: O(n log maxY), Space: O(1)
class Solution {
 public:
  double separateSquares(vector<vector<int>>& squares) {
    return 0.0;
  }
};
```
