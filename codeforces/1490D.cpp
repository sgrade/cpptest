// D. Permutation Transformation

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n;
vector<int> a;
int d;
vector<int> ans(n + 1);


void explore (int l, int r) {

    if (l > r) {
        return;
    }

    int mx_idx = distance(a.begin(), max_element(a.begin() + l, a.begin() + r + 1));
    
    ++d;
    explore(l, mx_idx - 1);
    explore(mx_idx + 1, r);
    --d;

    ans[mx_idx] = d;
    return;
}


int main() {

    int t;
    cin >> t;

    while (t--) {

        cin >> n;

        a.clear();
        a.resize(n + 1);
        for (int i = 1; i < n + 1; ++i) {
            cin >> a[i];
        }
        
        d = 0;
        ans.clear();
        ans.resize(n + 1);
        explore(1, n);

        for (int i = 1; i < n + 1; ++i) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }


    return 0;
}
