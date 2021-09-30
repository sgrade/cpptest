// B. Shifting Sort

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &el: a) {
            cin >> el;
        }
    
        vector<int> a_sorted(begin(a), end(a));
        sort(begin(a_sorted), end(a_sorted));

        vector<vector<int>> output;
        
        int target;
        for (int i = 0; i < n; ++i) {
            target = a_sorted[i];

            if (a[i] == target) {
                continue;
            }

            for (int j = i+1; j < n; ++j) {
                if (a[j] == target) {
                    output.push_back(vector<int>{i+1, j+1, j-i});
                    for (int k = j-1; k >= i; --k) {
                        a[k+1] = a[k];
                    }
                    a[i] = target;
                    break;
                }
            }
        }

        cout << size(output) << '\n';
        for (auto &v: output) {
            for (auto &el: v) {
                cout << el << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
