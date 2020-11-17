// A. Buy the String

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, c0, c1, h;
        cin >> n >> c0 >> c1 >> h;

        string s;
        getline(cin >> ws, s);

        int zeros = count(s.begin(), s.end(), '0');
        int ones = count(s.begin(), s.end(), '1');

        int ans = 0;

        if (c1 > c0 + h){
            // convert 1 to 0
            zeros += ones;
            ans += h * ones;
            ones = 0;
        }
        else if (c0 > c1 + h){
            // convert 0 to 1
            ones += zeros;
            ans += h * zeros;
            zeros = 0;
        }

        ans += zeros * c0 + ones * c1;

        cout << ans << endl;
    }

    return 0;
}
