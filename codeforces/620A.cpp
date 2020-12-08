// A. Professor GukiZ's Robot

#include <iostream>
#include <algorithm>

using namespace std;
using ll = unsigned long long;


int main(){

    ll x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    ll xDiff = llabs(x1 - x2);
    ll yDiff = llabs(y1 - y2);

    ll ans = min(xDiff, yDiff) + llabs(xDiff - yDiff);
    cout << ans << endl;

    return 0;
}
