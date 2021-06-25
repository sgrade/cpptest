// A. Pretty Permutations

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> ans(n);
        for (int i = 0; i < n; i += 2) {
            ans[i] = i + 2;
        }
        for (int i = 1; i < n; i += 2) {
            ans[i] = i;
        }
        if (n % 2 != 0) {
            --ans[n-1];
            swap(ans[n-1], ans[n-3]);
        }

        for (auto &el: ans) {
            cout << el << ' ';
        }
        cout << endl;

    }

    return 0;
}
