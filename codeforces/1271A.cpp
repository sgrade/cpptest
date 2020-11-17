// A. Suits
// Based on https://codeforces.com/contest/1271/submission/74211958

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d\n", &a, &b, &c, &d, &e, &f);

    int x, y;
    x = min(a, d);
    y = min({b, c, d});

    cout << max(x * e + min({b, c, d - x}) * f, y * f + min(a, d - y) * e) << endl;

    return 0;
}
