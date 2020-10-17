// A. Pasha and Stick

#include <iostream>

using namespace std;


int main(){

    int n;
    cin >> n;

    // Editorial - https://codeforces.com/blog/entry/22341
    int ans = 0;
    
    if (n%2 == 0){
        ans = n / 4;
        if (n%4 == 0){
            --ans;
        }
    }

    cout << ans << endl;

    return 0;
}