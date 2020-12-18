// A. Splitting in Teams

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    int a[n];
    for (auto &el: a) cin >> el;

    int ones = count(a, a+n, 1);
    int twos = count(a, a+n, 2);

    int ans = min(ones, twos);
    if (ones > twos) {
        ans += (ones - twos) / 3;
    }

    cout << ans << endl;

    return 0;
}
