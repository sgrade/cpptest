// B. Combinatorics Homework

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        vector<int> abc(3);
        for (auto &el: abc) {
            cin >> el;
        }
        sort(begin(abc), end(abc));

        int m;
        cin >> m;

        int min_pairs = abc[2] - (abc[1]+abc[0]) - 1;
        int max_pairs = accumulate(begin(abc), end(abc), 0) - 3;

        bool ans;
        
        if (m >= min_pairs && m <= max_pairs) {
            ans = true;
        }
        else {
            ans = false;
        }

        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
