// A. Friends Meeting

#include <algorithm>
#include <iostream>

using namespace std;


int main(){

    int x1, x2;
    cin >> x1 >> x2;

    int diff = abs(x1 - x2);
    int n = diff / 2;

    int ans = n * (n + 1);
    if (diff % 2 != 0) ans += n + 1;

    cout << ans << endl;

    return 0;
}
