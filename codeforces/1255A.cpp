// A. Changing Volume

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int a, b;
        cin >> a >> b;

        if (a < b){
            swap(a, b);
        }

        int ans = (a-b) / 5;
        a = (a-b) % 5;

        ans += a / 2;
        a = a % 2;

        ans += a;

        cout << ans << endl;

    }

    return 0;
}
