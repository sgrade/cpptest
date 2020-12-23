// A. Diagonal Walking

#include <iostream>
#include <string>

using namespace std;


int main(){

    int n;
    cin >> n;

    string s;
    getline(cin >> ws, s);

    // The idea about "+ 'X'" is from https://codeforces.com/contest/954/submission/68485638
    s += 'X';

    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans += 1;
        if (s[i] != s[i+1]) i += 1;
    }

    cout << ans << endl;

    return 0;
}
