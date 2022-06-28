// C. 3SUM Closure
// Time limit exceeded on pretest 3

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;


bool twoSum(vector<int>& nums, unordered_set<int>& a, int i, int left, int right) {
    int x;
    for (int left = i + 1; left < nums.size() - 1; ++left) {
        for (int right = nums.size() - 1; right > left; --right) {
            x = nums[i] + nums[left] + nums[right];
            if (a.find(x) != a.end()) {
                continue;
            }
            else {
                return false;
            }
        }
    }
    return true;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> A(n);
        unordered_set<int> a;
        for (int &el: A) {
            cin >> el;
            a.insert(el);
        }

        bool ans = true;

        sort(A.begin(), A.end());
        int left, right;
        for (int i = 0; i < n - 2; ++i) {
            if (i != 0 && (A[i-1] == A[i])) continue;
            left = i + 1;
            right = n - 1;
            if (!twoSum(A, a, i, left, right)) {
                ans = false;
                break;
            }
        }
        
        cout << (ans ? "YES\n" : "NO\n");

    }

    return 0;
}
