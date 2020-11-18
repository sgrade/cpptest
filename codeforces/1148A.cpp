// # A. Another One Bites The Dust

#include <iostream>
#include <algorithm>

using namespace std;
using ull = unsigned long long;


int main(){

    int a, b, c;
    cin >> a >> b >> c;

    ull x = min({a, b, c});
    a -= x;
    b -= x;
    c -= x;

    x *= 4;

    ull y = a == b ? a * 2 : min(a, b) * 2 + 1;

    cout << x + y + c * 2 << endl;

    return 0;
}
