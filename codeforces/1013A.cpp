// A. Piles With Stones

#include <iostream>
#include <numeric>

using namespace std;


int main(){

    int n;
    cin >> n;

    int x[n], y[n];
    for (auto &el: x) cin >> el;
    for (auto &el: y) cin >> el;

    int xSum = accumulate(x, x+n, 0);
    int ySum = accumulate(y, y+n, 0);

    cout << (xSum < ySum ? "NO" : "YES") << endl;

    return 0;
}
