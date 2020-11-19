// A. Shaass and Oskols

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    int a[n];
    for (auto &el: a) cin >> el;

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        --x;
        if (x - 1 >= 0) a[x-1] += max(0, y - 1);
        if (x + 1 < n) a[x+1] += a[x] - y;
        a[x] = 0;
    }

    for (auto el: a) cout << el << endl;

    return 0;
}
