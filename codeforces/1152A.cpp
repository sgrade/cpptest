// A. Neko Finds Grapes

#include <iostream>

using namespace std;


int main(){

    int n, m;
    cin >> n >> m;

    int a[n], b[m];
    
    int aEven = 0;
    for (auto &el: a) {
        cin >> el;
        if (el % 2 == 0) ++aEven;
    }

    int bOdd = 0;
    for (auto &el: b) {
        cin >> el;
        if (el % 2 != 0) ++ bOdd;
    }

    int ans = min(aEven, bOdd);
    ans += min(n - aEven, m - bOdd);

    cout << ans << endl;

    return 0;
}
