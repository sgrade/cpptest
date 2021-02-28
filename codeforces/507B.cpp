// B. Amr and Pins

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;


int main(){

    int r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;

    long long x = abs(x1 - x2), y = abs(y1 - y2);

    int ans = 0;

    if (x == y && x == 0) 
        ans = 0;
    else 
    {
        // Editorial - https://codeforces.com/blog/entry/15975
        double c = sqrtl(x * x + y * y);
        int dist = ceil(c);
        ans = dist / (2 * r);
        if (dist % (2 * r) != 0)
            ++ans;
    }

    cout << ans << endl;

    return 0;
}
