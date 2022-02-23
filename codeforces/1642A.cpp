// A. Hard Way

#include <iostream>
#include <map>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int ans = 0;

        map<int, vector<int>> yx;
        int x, y;
        for (int i = 0; i < 3; ++i) {
            cin >> x >> y;
            yx[y].push_back(x);
        }

        if (size(yx) == 2) {
            int y_bottom = begin(yx)->first;
            int y_top = rbegin(yx)->first;
            if (size(yx[y_top]) == 2) {
                ans = abs(yx[y_top][0] - yx[y_top][1]);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
