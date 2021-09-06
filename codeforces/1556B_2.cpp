// B. Take Your Places!

#include <iostream>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // Idea from https://codeforces.com/contest/1556/submission/127488579

        int num_of_odd = 0, num_of_even = 0, next_idx_odd = 0, next_idx_even = 1, swaps_odd = 0, swaps_even = 0;

        int current;
        for (int i = 0; i < n; ++i) {
            cin >> current;
            
            // current is odd
            if (current % 2 != 0) {
                ++num_of_odd;
                swaps_odd += abs(next_idx_odd - i);
                swaps_even += abs(next_idx_even - i);
                next_idx_odd += 2;
                next_idx_even += 2;
            }

            // current is even
            else {
                ++num_of_even;
            }
        }

        int ans;

        if (abs(num_of_odd - num_of_even) > 1) {
            ans = -1;
        }
        else if (num_of_odd == num_of_even) {
            ans = min(swaps_odd, swaps_even);
        }
        else if (num_of_odd > num_of_even) {
            ans = swaps_odd;
        }
        else {
            // num_of_even < num_of_odd
            ans = swaps_even;
        }

        cout << ans << endl;

    }

    return 0;
}
