// B. Woeful Permutation

#include <iostream>
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

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = i + 1;
        }
        
        if (n % 2 == 0) {
            for (int i = 1; i < n; i += 2) {
                swap(ans[i], ans[i - 1]);
            }
        }
        else {
            for (int i = 2; i < n; i += 2) {
                swap(ans[i], ans[i - 1]);
            }
        }

        for (int &el: ans) {
            cout << el << ' ';
        }
        cout << '\n';
    }
}