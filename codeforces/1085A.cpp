// A. Right-Left Cipher

#include <iostream>
#include <string>

using namespace std;


int main(){

    string s;
    getline(cin, s);

    int n = s.size();

    int mid = n / 2;
    if (n%2 == 0) --mid;

    string ans (1, s[mid]);
    int rng = 1;

    while(true){
        if (mid+rng < n) (ans += s[mid+rng]);
        else break;

        if (mid-rng >= 0) (ans += s[mid-rng]);
        else break;

        ++rng;
    }

    cout << ans << endl;

    return 0;
}
