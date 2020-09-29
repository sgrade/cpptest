// A. Shovels and Swords

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int a, b;
        cin >> a >> b;

        // Editorial - https://codeforces.com/blog/entry/78735

        int ans = min({a, b, (a+b)/3});

        cout << ans << endl;
        
    }

    return 0;
}