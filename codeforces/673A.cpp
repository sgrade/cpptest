// A. Bear and Game

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    int t[n];
    for (auto &el: t) cin >> el;

    int ans = 0;

    if (t[0] <= 15){
        for (int i = 0; i < n; ++i){
            ans = t[i];
            if (i != n - 1){
                if (t[i+1] - t[i] > 15) break;
            }
        }
    }

    ans = min(ans + 15, 90);

    cout << ans << endl;

    return 0;
}
