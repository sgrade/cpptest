// A. Sereja and Mugs

#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;


int main(){

    int n, s;
    cin >> n >> s;

    int a[n];
    for(auto &el: a) cin >> el;

    sort(a, a+n);

    int sm = accumulate(a, a+n-1, 0);

    cout << (sm <= s ? "YES" : "NO") << endl;

    return 0;
}
