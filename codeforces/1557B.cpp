// B. Moamen and k-subarrays

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        // Editorial - https://codeforces.com/blog/entry/93703

        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        
        bool ans = true;

        sort(begin(a), end(a));

        int num_of_arrays = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i].second - a[i-1].second != 1) {
                ++num_of_arrays;
            }
            if (num_of_arrays > k) {
                ans = false;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
