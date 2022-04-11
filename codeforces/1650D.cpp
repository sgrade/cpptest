// D. Twist the Permutation

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n+1);
        for (int i = 1; i < n + 1; ++i) {
            cin >> a[i];
        }

        // Editorial - https://codeforces.com/blog/entry/100712
        // Clarification - https://www.youtube.com/watch?v=bN7Xf_v-m1w
        
        vector<int> output(n+1);

        int d, idx;

        for (int i = n; i > 0; --i) {

            idx = distance(begin(a), find(begin(a), end(a), i));
            d = idx % i;
            
            output[i] = d;
            rotate(begin(a) + 1, begin(a) + 1 + d, begin(a) + 1 + i);
        }

        for (int i = 1; i < n + 1; ++i) {
            cout << output[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
