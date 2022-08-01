// C. Minimum Varied Number

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> digits = {9, 8, 7, 6, 5, 4, 3, 2, 1};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> ans;

        int x = n;
        while (x > 0) {
            for (int i = 0; i < 10; ++i) {
                if (x >= digits[i] && find(ans.begin(), ans.end(), digits[i]) == ans.end()) {
                    x -= digits[i];
                    ans.emplace_back(digits[i]);
                    break;
                }
            }
        }

        sort(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i];
        }
        cout << '\n';
    }

    return 0;
}
