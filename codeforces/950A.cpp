// A. Left-handers, Right-handers and Ambidexters

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int l, r, a;
    cin >> l >> r >> a;

    int x = min(l, r);
    l -= x;
    r -= x;

    int y = min(max(l, r), a);
    a -= y;

    cout << (x + y + a/2) * 2 << endl;

    return 0;
}
