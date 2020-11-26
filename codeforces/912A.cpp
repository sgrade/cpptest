// A. Tricky Alchemy

#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;


int main(){

    ll a, b;
    cin >> a >> b;
    ll x, y, z;
    cin >> x >> y >> z;

    ll required_a = x * 2 + y;
    ll required_b = y + z * 3;
    cout << (max(0LL, required_a - a) + max(0LL, required_b - b)) << endl;

    return 0;
}
