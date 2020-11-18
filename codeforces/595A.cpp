// A. Vitaly and Night

#include <iostream>

using namespace std;


int main(){

    int n, m;
    cin >> n >> m;

    int ans = 0;
    
    for (int i = 0; i < n; ++i){
        int a[2 * m];
        for (auto &el: a) cin >> el;
        for (int j = 0; j < 2 * m; j+=2){
            if (a[j] == 1 || a[j+1] == 1) ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}
