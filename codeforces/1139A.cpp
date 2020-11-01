// A. Even Substrings

#include <iostream>
#include <string>

using namespace std;


int main(){

    int n;
    cin >> n;

    string s;
    getline(cin >> ws, s);

    int ans = 0;
    for (int i=0; i<n; ++i){
        if (((int)s[i] - 48) % 2 == 0){
            ans += i + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
