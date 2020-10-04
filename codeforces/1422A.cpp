// A. Fence

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int a[3], d;
        cin >> a[0] >> a[1] >> a[2];

        sort(a, a+3);

        int ans = a[2] - (a[0] + a[1]) + 1;
        while(ans <=0) ++ ans;

        cout << ans << endl;

    }

    return 0;
}