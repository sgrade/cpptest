// B. Move and Turn

#include <iostream>

using namespace std;


int main(){

    int n;
    cin >> n;

    int ans;

    int scaler;

    if (n%2 != 0){
        ans = 4;
        scaler = 1;
        for (int i = 3; i < n+1; i += 2){
            ans += 4 * (i - scaler);
            ++scaler;
        }
    }

    else{
        scaler = 1;
        for (int i = 2; i < n+1; i += 2) scaler += 1;
        ans = scaler * scaler;
    }

    cout << ans << endl;

    return 0;
}
