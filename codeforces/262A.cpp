// A. Roma and Lucky Numbers

#include <iostream>
#include <string>

using namespace std;


int main(){

    int n, k;
    cin >> n >> k;

    string a[n];
    for (auto &el: a) cin >> el;

    int ans = 0;

    for (auto x: a){
        int count = 0;
        for (int i = 0; i < x.size(); ++i){
            if (x[i] == '4' || x[i] == '7') ++count;
            if (count > k) break;
        }
        if (count <= k) ++ans;
    }

    cout << ans << endl;

    return 0;
}
