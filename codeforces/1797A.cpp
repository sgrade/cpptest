// A. Li Hua and Maze

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

        int n, m;
        cin >> n >> m;

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
              
        int ans1 = 0;
        if (x1 > 1) ++ans1;
        if (x1 < n) ++ans1;
        if (y1 > 1) ++ans1;
        if (y1 < m) ++ans1;
        
        int ans2 = 0;
        if (x2 > 1) ++ans2;
        if (x2 < n) ++ans2;
        if (y2 > 1) ++ans2;
        if (y2 < m) ++ans2;

        int ans = min(ans1, ans2);

        cout << ans << endl;

    }

    return 0;
}
