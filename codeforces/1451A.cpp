// A. Subtract or Divide

#include <iostream>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

int main(){

    int t;
    cin >> t;

    while(t--){

        ull n;
        cin >> n;

        ull ans = 0;
        if (n == 2) ans = 1;
        else if (n == 3) ans = 2;
        else if (n > 3){
            if (n % 2 == 0) ans = 2;
            else ans = 3;
        }

        cout << ans << endl;

    }

    return 0;
}
