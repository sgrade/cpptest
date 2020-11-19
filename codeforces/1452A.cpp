// A. Robot Program

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int x, y;
        cin >> x >> y;

        int ans = 0;
        if (x == y) ans = x + y;
        else{
            int m = max(x, y);
            ans = m + m - 1;
        }

        cout << ans << endl;

    }

    return 0;
}
