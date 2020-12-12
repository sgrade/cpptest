// A. String Generation

#include <iostream>
#include <string>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        string s = "abc";

        string ans;
        for (int i = 0; i < n / 3; ++i) ans += s;
        ans += s.substr(0, n%3);

        cout << ans << endl;
    }

    return 0;
}
