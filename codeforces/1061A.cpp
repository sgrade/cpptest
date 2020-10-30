// A. Coins

#include <iostream>

using namespace std;


int main(){

    int n, S;
    cin >> n >> S;

    int ans = S / n;
    if (S%n != 0) ++ans;

    cout << ans << endl;

    return 0;
}
