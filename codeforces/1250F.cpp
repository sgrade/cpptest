// F. Data Center

#include <iostream>
#include <math.h>
#include <limits>

using namespace std;


int main() {

    int n;
    cin >> n;

    int a, b;

    int ans = numeric_limits<int>::max();

    for (a = 1; a <= sqrt(n); ++a) {
        int area;
        for (b = 1; a * b <= n; ++b) {
            if (a * b == n) {
                ans = min(ans, 2 * a + 2 * b);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
