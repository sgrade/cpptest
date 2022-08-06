// C. Build Permutation

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> squares;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int x = 0;
    while (x * x <= 100000) {
        squares.emplace_back(x * x);
        ++x;
    }
    squares.emplace_back(x * x);

    while (t--) {

        int n;
        cin >> n;

        vector<int> ans(n);
        int i = n - 1;
        int prev_i = n - 1;
        vector<int>::iterator next_square_it = upper_bound(squares.begin(), squares.end(), i);
        int next_square_idx = distance(squares.begin(), next_square_it);
        int next_square;
        int nxt_el;
        while (i >= 0) {
            next_square = squares[next_square_idx];
            nxt_el = next_square - i;
            int x = nxt_el;
            while (x <= prev_i) {
                ans[i] = x;
                --i;
                ++x;
            }
            --next_square_idx;
            prev_i = i;
        }

        for (int &el: ans) {
            cout << el << ' ';
        }
        cout << '\n';
    }

    return 0;
}
