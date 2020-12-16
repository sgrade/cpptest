// B. Sale

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int n, m;
    cin >> n >> m;

    int a[n];
    for (auto &el: a) cin >> el;
    
    sort(a, a+n);

    int ans = 0;
    for (int i = 0; i < m; ++i){
        if (a[i] < 0) ans += -a[i];
        else break;
    }

    cout << ans << endl;

    return 0;
}
