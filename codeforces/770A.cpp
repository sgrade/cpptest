// A. New Password

#include <iostream>
#include <string>

using namespace std;


int main(){

    int n, k;
    cin >> n >> k;

    string ans;
    int i = 0;
    while(i < n){
        for(int j = 97; j < 97 + min(k, n-i); ++j) ans += char(j);
        i += k;
    }

    cout << ans << endl;

    return 0;
}
