// A. Beru-taxi

#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    int n;
    cin >> n;

    double ans = numeric_limits<double>::max(), cur_ans, dist;

    int x, y, v;
    while (n--) {
        cin >> x >> y >> v;

        // Idea for hypot is from https://codeforces.com/contest/706/submission/19787834
        // https://en.cppreference.com/w/cpp/numeric/math/hypot

        dist = hypot(x - a + 0., y - b + 0.);
        cur_ans = dist / v;
        ans = min(cur_ans, ans);
    }

    cout << setprecision(12) << ans << '\n';

    return 0;
}
