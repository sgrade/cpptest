// C. Alya and Permutation
// https://codeforces.com/contest/2035/problem/C

#include <bits/stdc++.h>

using namespace std;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        // Editorial - https://codeforces.com/blog/entry/135609
        // Basde on https://codeforces.com/contest/2035/submission/288397556
        set<int> st;
        for (int i = 1; i <= n; ++i)
            st.emplace(i);
        
        int k;
        vector<int> nums(n + 1);

        int prev_power_of_two = 1;
        while (prev_power_of_two << 1 <= n)
            prev_power_of_two <<= 1;
        
        if (n & 1) {
            k = n;
            int rightmost_bit = n & (-n);
            nums[n - 3] = rightmost_bit;
            nums[n - 2] = rightmost_bit + (rightmost_bit == 1 ? 2 : 1);
            nums[n - 1] = n - rightmost_bit;
            nums[n] = n;
        }

        else {
            k = prev_power_of_two * 2 - 1;
            if (n == prev_power_of_two) {
                nums[n - 4] = 1;
                nums[n - 3] = 3;
                nums[n - 2] = n - 2;
                nums[n - 1] = n - 1;
                nums[n] = n;
            }
            else {
                nums[n - 2] = n;
                nums[n - 1] = n - 1;
                nums[n] = prev_power_of_two - 1;
            }
        }

        for (int i = 1; i < n + 1; ++i)
            st.erase(nums[i]);
        for (int i = 1; i < n + 1; ++i) {
            if (nums[i] == 0) {
                nums[i] = *st.begin();
                st.erase(nums[i]);
            }
        }

        cout << k << endl;
        for (int i = 1; i <= n; ++i)
            cout << nums[i] << ' ';
        cout << endl;
    }

    return 0;
}
