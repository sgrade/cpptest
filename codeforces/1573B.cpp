// B. Swaps

#include <iostream>
#include <vector>
#include <limits>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        // Editorial - https://codeforces.com/blog/entry/95086
        // Key ideas for implementation - https://codeforces.com/contest/1573/submission/129174259

        vector<int> pos(n+n+1);

        int tmp;
        for (int i = 1; i < n+1; ++i) {
            cin >> tmp;
            pos[tmp] = i;
        }
        for (int i = 1; i < n+1; ++i) {
            cin >> tmp;
            pos[tmp] = i;
        }

        int min_swaps_of_odd_digit = numeric_limits<int>::max(), swaps_of_even_digit;
        int ans = numeric_limits<int>::max();

        for (int i = 1; i < n+n; i+=2) {
            min_swaps_of_odd_digit = min(min_swaps_of_odd_digit, pos[i]);
            swaps_of_even_digit = pos[i+1];
            ans = min(ans, min_swaps_of_odd_digit + swaps_of_even_digit - 2);
        }

        cout << ans << endl;

    }

    return 0;
}
