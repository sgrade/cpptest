// A. Prefixes

#include <iostream>
#include <string>

using namespace std;


int main(){

    int n;
    cin >> n;
    string s;
    getline(cin >> ws, s);

    int ans = 0;
    // https://codeforces.com/blog/entry/69954
    for(int i=0; i<n; i+=2){
        if (s[i] == s[i+1]) {
            ++ans;
            s[i] = s[i]=='a' ? 'b' : 'a';
        }
    }

    cout << ans << endl;
    cout << s << endl;

    return 0;
}
