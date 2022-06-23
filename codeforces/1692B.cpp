// B. All Distinct

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

        vector<int> a(n);
        for (int &el: a) cin >> el;

        int ans;
        if (n == 1) {
            ans = 1;
        }

        else {
            sort(a.begin(), a.end());
            auto it = unique(a.begin(), a.end());

            int uniq = distance(a.begin(), it);
            int rest = n - uniq;
            if (rest % 2 == 0) {
                ans = uniq;
            }
            else {
                ans = max(0, uniq - 1);
            }
        }
        

        cout << ans << '\n';
    }

    return 0;
}
